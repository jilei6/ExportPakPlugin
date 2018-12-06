// Fill out your copyright notice in the Description page of Project Settings.

#include "MyExportPak.h"
// Fill out your copyright notice in the Description page of Project Settings.

#include "JsonObject.h"
#include "JsonWriter.h"
#include "JsonSerializer.h"
#include "AssetRegistryModule.h"
#include "Paths.h"
#include "FileHelper.h"
#include "SNotificationList.h"
#include "ScopedSlowTask.h"
#include "SecureHash.h"
#include "PlatformFilemanager.h"
#include "MessageDialog.h"

#include "ProjectTargetPlatformEditor/Public/Interfaces/IProjectTargetPlatformEditorModule.h"
#include "PlatformInfo.h"
#include "InstalledPlatformInfo.h"
#include "CookerSettings.h"
#include "App.h"
#include "UnrealEdMisc.h"
#include "UATHelper/Public/IUATHelperModule.h"
#include "EditorStyleSet.h"



DEFINE_LOG_CATEGORY(LogExportPak);

class FCookedAssetFileVisitor : public IPlatformFile::FDirectoryVisitor
{
public:
	FCookedAssetFileVisitor(const FString& InAssetFilename) :AssetFilename(InAssetFilename) {}

	virtual bool Visit(const TCHAR *FilenameOrDirectory, bool bIsDirectory) override
	{
		if (bIsDirectory)
		{
			return true;
		}
		FString StandardizedFilename(FilenameOrDirectory);
		FPaths::MakeStandardFilename(StandardizedFilename);
		if (FPaths::GetBaseFilename(StandardizedFilename) == AssetFilename)
		{
			Files.Add(StandardizedFilename);
		}
		return true;
	}

	TArray<FString> Files;

private:
	FString AssetFilename;
};

void UMyExportPak::ClickMakePak(const FString& path, bool bIsIOS)
{
	ExportPakSettings = UExportPakSettings::Get();
	ExportPakSettings->bUseBatchMode = true;
	ExportPakSettings->bIsIOSMode = bIsIOS;
	FFilePath currPath;
	currPath.FilePath = path;
	ExportPakSettings->PackagesToExport.Empty();
	ExportPakSettings->PackagesToExport.Add(currPath);

	TMap<FString, FDependenciesInfo> DependenciesInfos;

	GetAssetDependecies(DependenciesInfos);

	SaveDependenciesInfo(DependenciesInfos);

	GeneratePakFiles(DependenciesInfos);
}

void UMyExportPak::GetAssetDependecies(TMap<FString, FDependenciesInfo>& DependenciesInfos)
{
	for (auto &PackageFilePath : ExportPakSettings->PackagesToExport)
	{
		FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));

		FStringAssetReference AssetRef = PackageFilePath.FilePath;
		FString TargetLongPackageName = AssetRef.GetLongPackageName();

		if (FPackageName::DoesPackageExist(TargetLongPackageName))
		{
			auto &DependenciesInfoEntry = DependenciesInfos.Add(TargetLongPackageName);

			// Try get asset type.
			{
				TArray<FAssetData> AssetDataList;
				bool  bResult = AssetRegistryModule.Get().GetAssetsByPackageName(FName(*TargetLongPackageName), AssetDataList);
				if (!bResult || AssetDataList.Num() == 0)
				{
					UE_LOG(LogExportPak, Error, TEXT("Failed to get AssetData of  %s, please check."), *TargetLongPackageName);
					return;
				}

				if (AssetDataList.Num() > 1)
				{
					UE_LOG(LogExportPak, Error, TEXT("Got multiple AssetData of  %s, please check."), *TargetLongPackageName);
				}

				DependenciesInfoEntry.AssetClassString = AssetDataList[0].AssetClass.ToString();
			}

			GatherDependenciesInfoRecursively(AssetRegistryModule, TargetLongPackageName, DependenciesInfoEntry.DependenciesInGameContentDir, DependenciesInfoEntry.OtherDependencies);
		}

		TArray<FName>  ACs;
		AssetRegistryModule.Get().GetAncestorClassNames(*TargetLongPackageName, ACs);
	}
}

void UMyExportPak::SaveDependenciesInfo(const TMap<FString, FDependenciesInfo> &DependenciesInfos)
{
	TSharedPtr<FJsonObject> RootJsonObject = MakeShareable(new FJsonObject);
	for (auto &DependenciesInfoEntry : DependenciesInfos)
	{
		TSharedPtr<FJsonObject> EntryJsonObject = MakeShareable(new FJsonObject);

		// Write current AssetClass.
		EntryJsonObject->SetStringField("AssetClass", DependenciesInfoEntry.Value.AssetClassString);

		// Write dependencies in game content dir.
		{
			TArray< TSharedPtr<FJsonValue> > DependenciesEntry;
			for (auto &d : DependenciesInfoEntry.Value.DependenciesInGameContentDir)
			{
				DependenciesEntry.Add(MakeShareable(new FJsonValueString(d)));
			}
			EntryJsonObject->SetArrayField("DependenciesInGameContentDir", DependenciesEntry);
		}

		// Write dependencies not in game content dir.
		{
			TArray< TSharedPtr<FJsonValue> > DependenciesEntry;
			for (auto &d : DependenciesInfoEntry.Value.OtherDependencies)
			{
				DependenciesEntry.Add(MakeShareable(new FJsonValueString(d)));
			}
			EntryJsonObject->SetArrayField("OtherDependencies", DependenciesEntry);
		}

		RootJsonObject->SetObjectField(DependenciesInfoEntry.Key, EntryJsonObject);
	}

	FString OutputString;
	auto JsonWirter = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(RootJsonObject.ToSharedRef(), JsonWirter);

	FString ResultFileFilename = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("ExportPak"), TEXT("/AssetDependencies.json"));
	ResultFileFilename = FPaths::ConvertRelativePathToFull(ResultFileFilename);

	// Attention to FFileHelper::EEncodingOptions::ForceUTF8 here.
	// In some case, UE4 will save as UTF16 according to the content.
	bool bSaveSuccess = FFileHelper::SaveStringToFile(OutputString, *ResultFileFilename, FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM);
	if (bSaveSuccess)
	{
		// UE4 API to show an editor notification.
		//auto Message = LOCTEXT("ExportPakSuccessNotification", "Succeed to export asset dependecies.");
		//FNotificationInfo Info(Message);
		//Info.bFireAndForget = true;
		//Info.ExpireDuration = 5.0f;
		//Info.bUseSuccessFailIcons = false;
		//Info.bUseLargeFont = false;

		//const FString HyperLinkText = ResultFileFilename;
		//Info.Hyperlink = FSimpleDelegate::CreateStatic([](FString SourceFilePath)
		//{
		//	FPlatformProcess::ExploreFolder(*SourceFilePath);
		//}, HyperLinkText);
		//Info.HyperlinkText = FText::FromString(HyperLinkText);

		//FSlateNotificationManager::Get().AddNotification(Info)->SetCompletionState(SNotificationItem::CS_Success);
	}
	else
	{
		UE_LOG(LogExportPak, Error, TEXT("Failed to export %s"), *ResultFileFilename);
	}
}

void UMyExportPak::GeneratePakFiles(const TMap<FString, FDependenciesInfo> &DependenciesInfos)
{
	float AmountOfWorkProgress = static_cast<float>(DependenciesInfos.Num());
	float CurrentProgress = 0.0f;
	FScopedSlowTask SlowTask(AmountOfWorkProgress);
	SlowTask.MakeDialog();
	for (auto &DependencyInfo : DependenciesInfos)
	{
		SlowTask.EnterProgressFrame(CurrentProgress, FText::Format(NSLOCTEXT("ExportPak", "GeneratePakFiles", "Exporting Paks of asset: {0}"), FText::FromString(DependencyInfo.Key)));

		FString HashedLongPackageName = HashStringWithSHA1(DependencyInfo.Key);
		TArray<FString> PackagesToHandle = DependencyInfo.Value.DependenciesInGameContentDir;
		//test
		for (int32 i = 0; i < DependencyInfo.Value.OtherDependencies.Num(); ++i)
		{
			PackagesToHandle.Add(DependencyInfo.Value.OtherDependencies[i]);
		}
		//test
		PackagesToHandle.Add(DependencyInfo.Key);

		if (ExportPakSettings->bUseBatchMode)
		{
			GenerateBatchPakFiles(PackagesToHandle, DependencyInfo.Key);
		}
		else
		{
			GenerateIndividualPakFiles(PackagesToHandle, DependencyInfo.Key);
		}

		SavePakDescriptionFile(DependencyInfo.Key, DependencyInfo.Value);
		CurrentProgress += 1.0f;
	}
}

void UMyExportPak::GenerateBatchPakFiles(const TArray<FString>& PackagesToHandle, const FString& MainPackage)
{
	FString HashedMainPackageName = HashStringWithSHA1(MainPackage);
	FString PakOutputDirectory = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("ExportPak/Paks"), HashedMainPackageName);

	FString ResponseFileContent = "";

	for (auto& PackageNameInGameDir : PackagesToHandle)
	{
		// Standardize package name. May this is not necessary.
		FString TargetLongPackageName;
		{
			FString FailedReason;
			bool bConvertionResult = FPackageName::TryConvertFilenameToLongPackageName(
				PackageNameInGameDir,
				TargetLongPackageName,
				&FailedReason
			);

			if (!bConvertionResult)
			{
				UE_LOG(LogExportPak, Error, TEXT("        TryConvertFilenameToLongPackageName Failed: %s!"), *FailedReason);
				return;
			}
			else
			{
				UE_LOG(LogExportPak, Log, TEXT("        %s"), *TargetLongPackageName);
			}
		}

		FString TargetAssetFilepath;
		{
			bool bConvertionResult = FPackageName::TryConvertLongPackageNameToFilename(
				TargetLongPackageName,
				TargetAssetFilepath,
				".uasset"
			);
			if (!bConvertionResult)
			{
				UE_LOG(LogExportPak, Error, TEXT("        TryConvertLongPackageNameToFilename Failed!"));
				return;
			}
			else
			{
				UE_LOG(LogExportPak, Log, TEXT("            %s"), *TargetAssetFilepath);
			}
		}

		FString Filename = FPaths::GetBaseFilename(TargetAssetFilepath);
		//test
		FString TestPathname = FPaths::GetPath(TargetAssetFilepath);
		FString ProjectName = FPaths::GetBaseFilename(FPaths::GetProjectFilePath());
		FString IntermediateDirectory = FPaths::GetPath(TargetAssetFilepath).Replace(*FPaths::ProjectDir(), TEXT(""), ESearchCase::CaseSensitive);
		
		// TODO ArcEcho: Now it is hard-coded to WindowsNoEditor
		FString TargetStr = (ExportPakSettings->bIsIOSMode == true) ? TEXT("Cooked/IOS") : TEXT("Cooked/WindowsNoEditor");
		FString TargetCookedAssetDirectory = FPaths::Combine(FPaths::ProjectSavedDir(), TargetStr, ProjectName, IntermediateDirectory);

		//test
		FString FinalStr;
		if (TestPathname.Contains(TEXT("/Engine/Content")))
		{
			TargetLongPackageName.InsertAt(7, TEXT("/Content"));
			FinalStr = FPaths::GetPath(TargetLongPackageName);
			TargetCookedAssetDirectory = FPaths::Combine(FPaths::ProjectSavedDir(), TargetStr, FinalStr);
		}
		//test

		FCookedAssetFileVisitor CookedAssetFileVisitor(Filename);
		FPlatformFileManager::Get().GetPlatformFile().IterateDirectory(*TargetCookedAssetDirectory, CookedAssetFileVisitor);

		for (auto &f : CookedAssetFileVisitor.Files)
		{
			FString Ext = FPaths::GetExtension(f);
			FString RelativePathForResponseFile = FPaths::Combine(TEXT("../../.."), ProjectName, IntermediateDirectory, Filename) + FString(".") + Ext;

			if (f.Contains(TEXT("/Engine/Content")))
			{
				RelativePathForResponseFile = FPaths::Combine(TEXT("../../.."), FinalStr, Filename) + FString(".") + Ext;
			}
			ResponseFileContent += FString::Printf(TEXT("\"%s\" \"%s\" -compress\n"), *f, *RelativePathForResponseFile);
		}
	}

	FString HashedPackageName = HashStringWithSHA1(MainPackage);
	FString LogFilepath = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("ExportPak/Temp"), HashedPackageName + ".log");
	FString OutputPakFilepath = FPaths::Combine(PakOutputDirectory, HashedPackageName + TEXT(".pak"));

	FString ResponseFilepath = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("ExportPak/Temp"), HashedPackageName + "_Paklist.txt");
	FFileHelper::SaveStringToFile(ResponseFileContent, *ResponseFilepath);

	FString UnrealPakExeFilepath = FPaths::Combine(FPaths::EngineDir(), TEXT("Binaries/Win64/UnrealPak.exe"));
	FPaths::MakeStandardFilename(UnrealPakExeFilepath);
	UnrealPakExeFilepath = FPaths::ConvertRelativePathToFull(UnrealPakExeFilepath);

	FString CommandLine;
	if (ExportPakSettings->bIsIOSMode)
	{
		CommandLine = FString::Printf(
			TEXT("%s -create=%s -encryptionini -platform=IOS -installed -UTF8Output -multiprocess -patchpaddingalign=2048 -abslog=%s"),
			*OutputPakFilepath,
			*ResponseFilepath,
			*LogFilepath
		);
	}
	else
	{
		CommandLine = FString::Printf(
			TEXT("%s -create=%s -encryptionini -platform=Windows -installed -UTF8Output -multiprocess -patchpaddingalign=2048 -abslog=%s"),
			*OutputPakFilepath,
			*ResponseFilepath,
			*LogFilepath
		);
	}
	

	void* PipeRead = nullptr;
	void* PipeWrite = nullptr;
	int32 ReturnCode = -1;

	verify(FPlatformProcess::CreatePipe(PipeRead, PipeWrite));
	bool bLaunchDetached = false;
	bool bLaunchHidden = true;
	bool bLaunchReallyHidden = true;
	uint32* OutProcessID = nullptr;
	int32 PriorityModifier = -1;
	const TCHAR* OptionalWorkingDirectory = nullptr;
	FProcHandle ProcessHandle = FPlatformProcess::CreateProc(
		*UnrealPakExeFilepath, *CommandLine,
		bLaunchDetached, bLaunchHidden, bLaunchReallyHidden,
		OutProcessID, PriorityModifier,
		OptionalWorkingDirectory,
		PipeWrite
	);

	if (ProcessHandle.IsValid())
	{
		FPlatformProcess::WaitForProc(ProcessHandle);
		FPlatformProcess::GetProcReturnCode(ProcessHandle, &ReturnCode);
		if (ReturnCode == 0)
		{
			TArray<FString> OutResults;
			const FString StdOut = FPlatformProcess::ReadPipe(PipeRead);
			StdOut.ParseIntoArray(OutResults, TEXT("\n"), true);
			UE_LOG(LogExportPak, Log, TEXT("ExportPak success:\n%s"), *StdOut);
		}
		else
		{
			TArray<FString> OutErrorMessages;
			const FString StdOut = FPlatformProcess::ReadPipe(PipeRead);
			StdOut.ParseIntoArray(OutErrorMessages, TEXT("\n"), true);
			UE_LOG(LogExportPak, Warning, TEXT("ExportPak Falied:\nReturnCode=%d\n%s"), ReturnCode, *StdOut);
		}

		FPlatformProcess::CloseProc(ProcessHandle);
		FPlatformProcess::ClosePipe(PipeRead, PipeWrite);
	}
	else
	{
		UE_LOG(LogExportPak, Error, TEXT(" Failed to launch unrealPak.exe: %s"), *UnrealPakExeFilepath);
	}

}

void UMyExportPak::GenerateIndividualPakFiles(const TArray<FString>& PackagesToHandle, const FString& MainPackage)
{
	FString HashedMainPackageName = HashStringWithSHA1(MainPackage);
	FString PakOutputDirectory = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("ExportPak/Paks"), HashedMainPackageName);

	float AmountOfWorkProgress = static_cast<float>(PackagesToHandle.Num());
	float CurrentProgress = 0.0f;
	FScopedSlowTask SlowTask(AmountOfWorkProgress);
	SlowTask.MakeDialog();
	for (auto& PackageNameInGameDir : PackagesToHandle)
	{
		// Standardize package name. May this is not necessary.
		FString TargetLongPackageName;
		{
			FString FailedReason;
			bool bConvertionResult = FPackageName::TryConvertFilenameToLongPackageName(
				PackageNameInGameDir,
				TargetLongPackageName,
				&FailedReason
			);

			if (!bConvertionResult)
			{
				UE_LOG(LogExportPak, Error, TEXT("        TryConvertFilenameToLongPackageName Failed: %s!"), *FailedReason);
				return;
			}
			else
			{
				UE_LOG(LogExportPak, Log, TEXT("        %s"), *TargetLongPackageName);
			}
		}

		SlowTask.EnterProgressFrame(CurrentProgress, FText::Format(NSLOCTEXT("ExportPak", "GenerateIndividualPakFiles", "Dependent asset {0}"), FText::FromString(TargetLongPackageName)));

		FString TargetAssetFilepath;
		{
			bool bConvertionResult = FPackageName::TryConvertLongPackageNameToFilename(
				TargetLongPackageName,
				TargetAssetFilepath,
				".uasset"
			);
			if (!bConvertionResult)
			{
				UE_LOG(LogExportPak, Error, TEXT("        TryConvertLongPackageNameToFilename Failed!"));
				return;
			}
			else
			{
				UE_LOG(LogExportPak, Log, TEXT("            %s"), *TargetAssetFilepath);
			}
		}

		FString Filename = FPaths::GetBaseFilename(TargetAssetFilepath);
		FString ProjectName = FPaths::GetBaseFilename(FPaths::GetProjectFilePath());
		FString IntermediateDirectory = FPaths::GetPath(TargetAssetFilepath).Replace(*FPaths::ProjectDir(), TEXT(""), ESearchCase::CaseSensitive);

		// TODO ArcEcho: Now it is hard-coded to WindowsNoEditor
		FString TargetCookedAssetDirectory = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("Cooked/WindowsNoEditor"), ProjectName, IntermediateDirectory);

		FCookedAssetFileVisitor CookedAssetFileVisitor(Filename);
		FPlatformFileManager::Get().GetPlatformFile().IterateDirectory(*TargetCookedAssetDirectory, CookedAssetFileVisitor);

		FString ResponseFileContent = "";
		for (auto &f : CookedAssetFileVisitor.Files)
		{
			FString Ext = FPaths::GetExtension(f);
			FString RelativePathForResponseFile = FPaths::Combine(TEXT("../../.."), ProjectName, IntermediateDirectory, Filename) + FString(".") + Ext;

			ResponseFileContent += FString::Printf(TEXT("\"%s\" \"%s\"\n"), *f, *RelativePathForResponseFile);

		}

		FString HashedPackageName = HashStringWithSHA1(PackageNameInGameDir);
		FString LogFilepath = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("ExportPak/Temp"), HashedPackageName + ".log");
		FString OutputPakFilepath = FPaths::Combine(PakOutputDirectory, HashedPackageName + TEXT(".pak"));

		FString ResponseFilepath = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("ExportPak/Temp"), HashedPackageName + "_Paklist.txt");
		FFileHelper::SaveStringToFile(ResponseFileContent, *ResponseFilepath);

		FString UnrealPakExeFilepath = FPaths::Combine(FPaths::EngineDir(), TEXT("Binaries/Win64/UnrealPak.exe"));
		FPaths::MakeStandardFilename(UnrealPakExeFilepath);
		UnrealPakExeFilepath = FPaths::ConvertRelativePathToFull(UnrealPakExeFilepath);

		FString CommandLine = FString::Printf(
			TEXT("%s -create=%s -encryptionini -platform=Windows -installed -UTF8Output -multiprocess -patchpaddingalign=2048 -abslog=%s -compress"),
			*OutputPakFilepath,
			*ResponseFilepath,
			*LogFilepath
		);

		void* PipeRead = nullptr;
		void* PipeWrite = nullptr;
		int32 ReturnCode = -1;

		verify(FPlatformProcess::CreatePipe(PipeRead, PipeWrite));
		bool bLaunchDetached = false;
		bool bLaunchHidden = true;
		bool bLaunchReallyHidden = true;
		uint32* OutProcessID = nullptr;
		int32 PriorityModifier = -1;
		const TCHAR* OptionalWorkingDirectory = nullptr;
		FProcHandle ProcessHandle = FPlatformProcess::CreateProc(
			*UnrealPakExeFilepath, *CommandLine,
			bLaunchDetached, bLaunchHidden, bLaunchReallyHidden,
			OutProcessID, PriorityModifier,
			OptionalWorkingDirectory,
			PipeWrite
		);


		if (ProcessHandle.IsValid())
		{
			FPlatformProcess::WaitForProc(ProcessHandle);
			FPlatformProcess::GetProcReturnCode(ProcessHandle, &ReturnCode);
			if (ReturnCode == 0)
			{
				TArray<FString> OutResults;
				const FString StdOut = FPlatformProcess::ReadPipe(PipeRead);
				StdOut.ParseIntoArray(OutResults, TEXT("\n"), true);
				UE_LOG(LogExportPak, Log, TEXT("ExportPak success:\n%s"), *StdOut);
			}
			else
			{
				TArray<FString> OutErrorMessages;
				const FString StdOut = FPlatformProcess::ReadPipe(PipeRead);
				StdOut.ParseIntoArray(OutErrorMessages, TEXT("\n"), true);
				UE_LOG(LogExportPak, Warning, TEXT("ExportPak Falied:\nReturnCode=%d\n%s"), ReturnCode, *StdOut);
			}

			FPlatformProcess::ClosePipe(PipeRead, PipeWrite);
			FPlatformProcess::CloseProc(ProcessHandle);
		}
		else
		{
			UE_LOG(LogExportPak, Error, TEXT(" Failed to launch unrealPak.exe: %s"), *UnrealPakExeFilepath);
		}

		CurrentProgress += 1.0f;
	}
}

void UMyExportPak::SavePakDescriptionFile(const FString& TargetPackage, const FDependenciesInfo& DependecyInfo)
{
	FString HashedMainPackageName = HashStringWithSHA1(TargetPackage);
	FString PakOutputDirectory = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("ExportPak/Paks"), HashedMainPackageName);

	TSharedPtr<FJsonObject> RootJsonObject = MakeShareable(new FJsonObject);
	{
		RootJsonObject->SetStringField("long_package_name", TargetPackage);

		FString PakFilepath = FPaths::Combine(PakOutputDirectory, HashedMainPackageName + TEXT(".pak"));

		RootJsonObject->SetStringField("pak_file", HashedMainPackageName + TEXT(".pak"));
		RootJsonObject->SetStringField("asset_class", DependecyInfo.AssetClassString);

		FString FileSizeInBytes = FString::Printf(TEXT("%lld"), FPlatformFileManager::Get().GetPlatformFile().FileSize(*PakFilepath));
		RootJsonObject->SetStringField("file_size_in_bytes", FileSizeInBytes);
	}

	TArray<TSharedPtr<FJsonValue>> DependencyEntries;
	for (const auto& DependencyInGameContentDir : DependecyInfo.DependenciesInGameContentDir)
	{
		TSharedPtr<FJsonObject> EntryJsonObject = MakeShareable(new FJsonObject);

		FString HashedPackageName = HashStringWithSHA1(DependencyInGameContentDir);
		FString PakFilepath = FPaths::Combine(PakOutputDirectory, HashedPackageName + TEXT(".pak"));
		FString FileSizeInBytes = FString::Printf(TEXT("%lld"), FPlatformFileManager::Get().GetPlatformFile().FileSize(*PakFilepath));

		EntryJsonObject->SetStringField("long_package_name", DependencyInGameContentDir);
		EntryJsonObject->SetStringField("pak_file", HashedPackageName + TEXT(".pak"));
		EntryJsonObject->SetStringField("file_size_in_bytes", FileSizeInBytes);

		TSharedRef< FJsonValueObject > JsonValue = MakeShareable(new FJsonValueObject(EntryJsonObject));
		DependencyEntries.Add(JsonValue);
	}
	RootJsonObject->SetArrayField("dependencies_in_game_content_dir", DependencyEntries);

	FString OutputString;
	auto JsonWirter = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(RootJsonObject.ToSharedRef(), JsonWirter);

	FString PakDescriptionFilename = FPaths::Combine(PakOutputDirectory, HashedMainPackageName + TEXT(".json"));
	PakDescriptionFilename = FPaths::ConvertRelativePathToFull(PakDescriptionFilename);

	// Attention to FFileHelper::EEncodingOptions::ForceUTF8 here.
	// In some case, UE4 will save as UTF16 according to the content.
	bool bSaveSuccess = FFileHelper::SaveStringToFile(OutputString, *PakDescriptionFilename, FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM);
	if (!bSaveSuccess)
	{
		UE_LOG(LogExportPak, Error, TEXT("Failed to save pak description file: %s"), *PakDescriptionFilename);
	}
}


void UMyExportPak::GatherDependenciesInfoRecursively(FAssetRegistryModule &AssetRegistryModule, const FString &TargetLongPackageName, TArray<FString> &DependenciesInGameContentDir, TArray<FString> &OtherDependencies)
{
	TArray<FName> Dependencies;
	bool bGetDependenciesSuccess = AssetRegistryModule.Get().GetDependencies(FName(*TargetLongPackageName), Dependencies, EAssetRegistryDependencyType::Packages);
	if (bGetDependenciesSuccess)
	{
		for (auto &d : Dependencies)
		{
			// Pick out packages in game content dir.
			FString LongDependentPackageName = d.ToString();
			if (LongDependentPackageName.StartsWith("/Game"))
			{
				// Try find firstly to avoid duplicated entry.
				if (DependenciesInGameContentDir.Find(LongDependentPackageName) == INDEX_NONE)
				{
					DependenciesInGameContentDir.Add(LongDependentPackageName);
					GatherDependenciesInfoRecursively(AssetRegistryModule, LongDependentPackageName, DependenciesInGameContentDir, OtherDependencies);
				}
			}
			else
			{
				if (OtherDependencies.Find(LongDependentPackageName) == INDEX_NONE)
				{
					OtherDependencies.Add(LongDependentPackageName);
					GatherDependenciesInfoRecursively(AssetRegistryModule, LongDependentPackageName, DependenciesInGameContentDir, OtherDependencies);
				}
			}
		}
	}
}

FString UMyExportPak::HashStringWithSHA1(const FString &InString)
{
	FSHAHash StringHash;
	FSHA1::HashBuffer(TCHAR_TO_ANSI(*InString), InString.Len(), StringHash.Hash);

	return StringHash.ToString();
}


void UMyExportPak::TestCook(const FName InPlatformInfoName)
{
	const PlatformInfo::FPlatformInfo* const PlatformInfoInst = PlatformInfo::FindPlatformInfo(InPlatformInfoName);
	if (PlatformInfoInst == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("ERROR PlatformInfo is nullptr"));
	}

	if (FInstalledPlatformInfo::Get().IsPlatformMissingRequiredFile(PlatformInfoInst->BinaryFolderName))
	{
		if (!FInstalledPlatformInfo::OpenInstallerOptions())
		{
			UE_LOG(LogTemp, Warning, TEXT("ERROR MissingPlatformFilesCook"));
		}
		return;
	}

	FString OptionalParams;

	if (!FModuleManager::LoadModuleChecked<IProjectTargetPlatformEditorModule>("ProjectTargetPlatformEditor").ShowUnsupportedTargetWarning(PlatformInfoInst->VanillaPlatformName))
	{
		return;
	}

	// Append any extra UAT flags specified for this platform flavor
	if (!PlatformInfoInst->UATCommandLine.IsEmpty())
	{
		OptionalParams += TEXT(" ");
		OptionalParams += PlatformInfoInst->UATCommandLine;
	}
	else
	{
		OptionalParams += TEXT(" -targetplatform=");
		OptionalParams += *PlatformInfoInst->TargetPlatformName.ToString();
	}

	//OptionalParams += GetCookingOptionalParams();

	UCookerSettings const* CookerSettings = GetDefault<UCookerSettings>();
	if (CookerSettings->bIterativeCookingForFileCookContent)
	{
		OptionalParams += TEXT(" -iterate");
	}

	if (FApp::IsRunningDebug())
	{
		OptionalParams += TEXT(" -UseDebugParamForEditorExe");
	}

	FString ProjectPath = FPaths::IsProjectFilePathSet() ? FPaths::ConvertRelativePathToFull(FPaths::GetProjectFilePath()) : FPaths::RootDir() / FApp::GetProjectName() / FApp::GetProjectName() + TEXT(".uproject");
	FString CommandLine = FString::Printf(TEXT("BuildCookRun %s%s -nop4 -project=\"%s\" -cook -skipstage -ue4exe=%s %s -utf8output"),
		GetUATCompilationFlags(),
		FApp::IsEngineInstalled() ? TEXT(" -installed") : TEXT(""),
		*ProjectPath,
		*FUnrealEdMisc::Get().GetExecutableForCommandlets(),
		*OptionalParams
	);

	IUATHelperModule::Get().CreateUatTask(CommandLine, PlatformInfoInst->DisplayName, FText::FromString(TEXT("Cooking content")), FText::FromString(TEXT("Cooking")), FEditorStyle::GetBrush(TEXT("MainFrame.CookContent")));

}

FString UMyExportPak::GetCookingOptionalParams()
{
	FString OptionalParams = TEXT("");
	/*const UProjectPackagingSettings* const PackagingSettings = GetDefault<UProjectPackagingSettings>();

	if (PackagingSettings->bSkipEditorContent)
	{
		OptionalParams += TEXT(" -SkipCookingEditorContent");
	}*/
	OptionalParams += TEXT(" -SkipCookingEditorContent");
	return OptionalParams;
}

const TCHAR* UMyExportPak::GetUATCompilationFlags()
{
	return (FApp::GetEngineIsPromotedBuild() || FApp::IsEngineInstalled())
		? TEXT("-nocompile -nocompileeditor")
		: TEXT("-nocompileeditor");
}