// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "MyExportPak.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogExportPak, Log, All);

class FAssetRegistryModule;

struct FDependenciesInfo
{
	TArray<FString> DependenciesInGameContentDir;
	TArray<FString> OtherDependencies;
	FString AssetClassString;
};


UCLASS(config = Game)
class UExportPakSettings : public UObject
{
	GENERATED_BODY()
public:
	UExportPakSettings() :bUseBatchMode(false), bIsIOSMode(false){}

	static UExportPakSettings* Get()
	{
		static bool bInitialized = false;
		// This is a singleton, use default object
		UExportPakSettings* DefaultSettings = GetMutableDefault<UExportPakSettings>();
		if (!bInitialized)
		{
			bInitialized = true;
		}
		return DefaultSettings;
	}

public:
	/** If true, package all assets into a single pak file.*/
	UPROPERTY(config, EditAnywhere, BlueprintReadWrite, Category = Default)
		bool  bUseBatchMode;

	UPROPERTY(config, EditAnywhere, BlueprintReadWrite, Category = Default)
		bool  bIsIOSMode;

	/** You can use copied asset string reference here, e.g. World'/Game/NewMap.NewMap'*/
	UPROPERTY(config, EditAnywhere, BlueprintReadWrite, Category = "Target Asset List")
		TArray<FFilePath> PackagesToExport;
};

/**
 * 
 */
UCLASS()
class EXPORTPAKPLUGIN_API UMyExportPak : public UObject
{
	GENERATED_BODY()
	
public:

	void ClickMakePak(const FString& path, bool bIsIOS);

	void GetAssetDependecies(TMap<FString, FDependenciesInfo>& DependenciesInfos);

	/** This will save the dependencies information to the OutputPath/AssetDependencies.json */
	void SaveDependenciesInfo(const TMap<FString, FDependenciesInfo> &DependenciesInfos);

	void GeneratePakFiles(const TMap<FString, FDependenciesInfo> &DependenciesInfos);

	//test cook
	void TestCook(const FName InPlatformInfoName);

	FString GetCookingOptionalParams();

	const TCHAR* GetUATCompilationFlags();

private:

	void GenerateBatchPakFiles(const TArray<FString>& PackagesToHandle, const FString& MainPackage);

	void GenerateIndividualPakFiles(const TArray<FString>& PackagesToHandle, const FString& MainPackage);

	void SavePakDescriptionFile(const FString& TargetPackage, const FDependenciesInfo& DependecyInfo);

	void GatherDependenciesInfoRecursively(FAssetRegistryModule &AssetRegistryModule, const FString &TargetLongPackageName,
		TArray<FString> &DependenciesInGameContentDir, TArray<FString> &OtherDependencies);

	FString HashStringWithSHA1(const FString &InString);

	UExportPakSettings* ExportPakSettings;
	
	
};
