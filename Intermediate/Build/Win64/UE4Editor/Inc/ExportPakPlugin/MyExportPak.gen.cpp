// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ExportPakPlugin/Public/MyExportPak.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyExportPak() {}
// Cross Module References
	EXPORTPAKPLUGIN_API UClass* Z_Construct_UClass_UExportPakSettings_NoRegister();
	EXPORTPAKPLUGIN_API UClass* Z_Construct_UClass_UExportPakSettings();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_ExportPakPlugin();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FFilePath();
	EXPORTPAKPLUGIN_API UClass* Z_Construct_UClass_UMyExportPak_NoRegister();
	EXPORTPAKPLUGIN_API UClass* Z_Construct_UClass_UMyExportPak();
// End Cross Module References
	void UExportPakSettings::StaticRegisterNativesUExportPakSettings()
	{
	}
	UClass* Z_Construct_UClass_UExportPakSettings_NoRegister()
	{
		return UExportPakSettings::StaticClass();
	}
	struct Z_Construct_UClass_UExportPakSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PackagesToExport_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_PackagesToExport;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PackagesToExport_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsIOSMode_MetaData[];
#endif
		static void NewProp_bIsIOSMode_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsIOSMode;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseBatchMode_MetaData[];
#endif
		static void NewProp_bUseBatchMode_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseBatchMode;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UExportPakSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_ExportPakPlugin,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UExportPakSettings_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MyExportPak.h" },
		{ "ModuleRelativePath", "Public/MyExportPak.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UExportPakSettings_Statics::NewProp_PackagesToExport_MetaData[] = {
		{ "Category", "Target Asset List" },
		{ "ModuleRelativePath", "Public/MyExportPak.h" },
		{ "ToolTip", "You can use copied asset string reference here, e.g. World'/Game/NewMap.NewMap'" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UExportPakSettings_Statics::NewProp_PackagesToExport = { UE4CodeGen_Private::EPropertyClass::Array, "PackagesToExport", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000004005, 1, nullptr, STRUCT_OFFSET(UExportPakSettings, PackagesToExport), METADATA_PARAMS(Z_Construct_UClass_UExportPakSettings_Statics::NewProp_PackagesToExport_MetaData, ARRAY_COUNT(Z_Construct_UClass_UExportPakSettings_Statics::NewProp_PackagesToExport_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UExportPakSettings_Statics::NewProp_PackagesToExport_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "PackagesToExport", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000004000, 1, nullptr, 0, Z_Construct_UScriptStruct_FFilePath, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UExportPakSettings_Statics::NewProp_bIsIOSMode_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Public/MyExportPak.h" },
	};
#endif
	void Z_Construct_UClass_UExportPakSettings_Statics::NewProp_bIsIOSMode_SetBit(void* Obj)
	{
		((UExportPakSettings*)Obj)->bIsIOSMode = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UExportPakSettings_Statics::NewProp_bIsIOSMode = { UE4CodeGen_Private::EPropertyClass::Bool, "bIsIOSMode", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000004005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UExportPakSettings), &Z_Construct_UClass_UExportPakSettings_Statics::NewProp_bIsIOSMode_SetBit, METADATA_PARAMS(Z_Construct_UClass_UExportPakSettings_Statics::NewProp_bIsIOSMode_MetaData, ARRAY_COUNT(Z_Construct_UClass_UExportPakSettings_Statics::NewProp_bIsIOSMode_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UExportPakSettings_Statics::NewProp_bUseBatchMode_MetaData[] = {
		{ "Category", "Default" },
		{ "ModuleRelativePath", "Public/MyExportPak.h" },
		{ "ToolTip", "If true, package all assets into a single pak file." },
	};
#endif
	void Z_Construct_UClass_UExportPakSettings_Statics::NewProp_bUseBatchMode_SetBit(void* Obj)
	{
		((UExportPakSettings*)Obj)->bUseBatchMode = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UExportPakSettings_Statics::NewProp_bUseBatchMode = { UE4CodeGen_Private::EPropertyClass::Bool, "bUseBatchMode", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000004005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UExportPakSettings), &Z_Construct_UClass_UExportPakSettings_Statics::NewProp_bUseBatchMode_SetBit, METADATA_PARAMS(Z_Construct_UClass_UExportPakSettings_Statics::NewProp_bUseBatchMode_MetaData, ARRAY_COUNT(Z_Construct_UClass_UExportPakSettings_Statics::NewProp_bUseBatchMode_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UExportPakSettings_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UExportPakSettings_Statics::NewProp_PackagesToExport,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UExportPakSettings_Statics::NewProp_PackagesToExport_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UExportPakSettings_Statics::NewProp_bIsIOSMode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UExportPakSettings_Statics::NewProp_bUseBatchMode,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UExportPakSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UExportPakSettings>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UExportPakSettings_Statics::ClassParams = {
		&UExportPakSettings::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000000A4u,
		nullptr, 0,
		Z_Construct_UClass_UExportPakSettings_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UExportPakSettings_Statics::PropPointers),
		"Game",
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UExportPakSettings_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UExportPakSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UExportPakSettings()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UExportPakSettings_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UExportPakSettings, 1185005849);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UExportPakSettings(Z_Construct_UClass_UExportPakSettings, &UExportPakSettings::StaticClass, TEXT("/Script/ExportPakPlugin"), TEXT("UExportPakSettings"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UExportPakSettings);
	void UMyExportPak::StaticRegisterNativesUMyExportPak()
	{
	}
	UClass* Z_Construct_UClass_UMyExportPak_NoRegister()
	{
		return UMyExportPak::StaticClass();
	}
	struct Z_Construct_UClass_UMyExportPak_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMyExportPak_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_ExportPakPlugin,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyExportPak_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MyExportPak.h" },
		{ "ModuleRelativePath", "Public/MyExportPak.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMyExportPak_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyExportPak>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMyExportPak_Statics::ClassParams = {
		&UMyExportPak::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UMyExportPak_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UMyExportPak_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMyExportPak()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMyExportPak_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMyExportPak, 2974156475);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMyExportPak(Z_Construct_UClass_UMyExportPak, &UMyExportPak::StaticClass, TEXT("/Script/ExportPakPlugin"), TEXT("UMyExportPak"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMyExportPak);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
