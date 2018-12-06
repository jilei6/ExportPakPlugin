// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ExportPakPlugin/Public/ExportPakPluginBPLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeExportPakPluginBPLibrary() {}
// Cross Module References
	EXPORTPAKPLUGIN_API UEnum* Z_Construct_UEnum_ExportPakPlugin_ECurrPlatform();
	UPackage* Z_Construct_UPackage__Script_ExportPakPlugin();
	EXPORTPAKPLUGIN_API UClass* Z_Construct_UClass_UExportPakPluginBPLibrary_NoRegister();
	EXPORTPAKPLUGIN_API UClass* Z_Construct_UClass_UExportPakPluginBPLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	EXPORTPAKPLUGIN_API UFunction* Z_Construct_UFunction_UExportPakPluginBPLibrary_CookContent();
	EXPORTPAKPLUGIN_API UFunction* Z_Construct_UFunction_UExportPakPluginBPLibrary_ExportPakPluginSampleFunction();
	EXPORTPAKPLUGIN_API UFunction* Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak();
// End Cross Module References
	static UEnum* ECurrPlatform_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_ExportPakPlugin_ECurrPlatform, Z_Construct_UPackage__Script_ExportPakPlugin(), TEXT("ECurrPlatform"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ECurrPlatform(ECurrPlatform_StaticEnum, TEXT("/Script/ExportPakPlugin"), TEXT("ECurrPlatform"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_ExportPakPlugin_ECurrPlatform_CRC() { return 789392845U; }
	UEnum* Z_Construct_UEnum_ExportPakPlugin_ECurrPlatform()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_ExportPakPlugin();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ECurrPlatform"), 0, Get_Z_Construct_UEnum_ExportPakPlugin_ECurrPlatform_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ECurrPlatform::Windows", (int64)ECurrPlatform::Windows },
				{ "ECurrPlatform::IOS", (int64)ECurrPlatform::IOS },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/ExportPakPluginBPLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_ExportPakPlugin,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"ECurrPlatform",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"ECurrPlatform",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void UExportPakPluginBPLibrary::StaticRegisterNativesUExportPakPluginBPLibrary()
	{
		UClass* Class = UExportPakPluginBPLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CookContent", &UExportPakPluginBPLibrary::execCookContent },
			{ "ExportPakPluginSampleFunction", &UExportPakPluginBPLibrary::execExportPakPluginSampleFunction },
			{ "MakePak", &UExportPakPluginBPLibrary::execMakePak },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UExportPakPluginBPLibrary_CookContent_Statics
	{
		struct ExportPakPluginBPLibrary_eventCookContent_Parms
		{
			ECurrPlatform CurrPlatform;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_CurrPlatform;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_CurrPlatform_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UExportPakPluginBPLibrary_CookContent_Statics::NewProp_CurrPlatform = { UE4CodeGen_Private::EPropertyClass::Enum, "CurrPlatform", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(ExportPakPluginBPLibrary_eventCookContent_Parms, CurrPlatform), Z_Construct_UEnum_ExportPakPlugin_ECurrPlatform, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UExportPakPluginBPLibrary_CookContent_Statics::NewProp_CurrPlatform_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UExportPakPluginBPLibrary_CookContent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExportPakPluginBPLibrary_CookContent_Statics::NewProp_CurrPlatform,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExportPakPluginBPLibrary_CookContent_Statics::NewProp_CurrPlatform_Underlying,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UExportPakPluginBPLibrary_CookContent_Statics::Function_MetaDataParams[] = {
		{ "Category", "myExportPakBpPlugin" },
		{ "ModuleRelativePath", "Public/ExportPakPluginBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UExportPakPluginBPLibrary_CookContent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UExportPakPluginBPLibrary, "CookContent", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(ExportPakPluginBPLibrary_eventCookContent_Parms), Z_Construct_UFunction_UExportPakPluginBPLibrary_CookContent_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UExportPakPluginBPLibrary_CookContent_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UExportPakPluginBPLibrary_CookContent_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UExportPakPluginBPLibrary_CookContent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UExportPakPluginBPLibrary_CookContent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UExportPakPluginBPLibrary_CookContent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UExportPakPluginBPLibrary_ExportPakPluginSampleFunction_Statics
	{
		struct ExportPakPluginBPLibrary_eventExportPakPluginSampleFunction_Parms
		{
			float Param;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Param;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UExportPakPluginBPLibrary_ExportPakPluginSampleFunction_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(ExportPakPluginBPLibrary_eventExportPakPluginSampleFunction_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UExportPakPluginBPLibrary_ExportPakPluginSampleFunction_Statics::NewProp_Param = { UE4CodeGen_Private::EPropertyClass::Float, "Param", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(ExportPakPluginBPLibrary_eventExportPakPluginSampleFunction_Parms, Param), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UExportPakPluginBPLibrary_ExportPakPluginSampleFunction_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExportPakPluginBPLibrary_ExportPakPluginSampleFunction_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExportPakPluginBPLibrary_ExportPakPluginSampleFunction_Statics::NewProp_Param,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UExportPakPluginBPLibrary_ExportPakPluginSampleFunction_Statics::Function_MetaDataParams[] = {
		{ "Category", "ExportPakPluginTesting" },
		{ "DisplayName", "Execute Sample function" },
		{ "Keywords", "ExportPakPlugin sample test testing" },
		{ "ModuleRelativePath", "Public/ExportPakPluginBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UExportPakPluginBPLibrary_ExportPakPluginSampleFunction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UExportPakPluginBPLibrary, "ExportPakPluginSampleFunction", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(ExportPakPluginBPLibrary_eventExportPakPluginSampleFunction_Parms), Z_Construct_UFunction_UExportPakPluginBPLibrary_ExportPakPluginSampleFunction_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UExportPakPluginBPLibrary_ExportPakPluginSampleFunction_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UExportPakPluginBPLibrary_ExportPakPluginSampleFunction_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UExportPakPluginBPLibrary_ExportPakPluginSampleFunction_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UExportPakPluginBPLibrary_ExportPakPluginSampleFunction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UExportPakPluginBPLibrary_ExportPakPluginSampleFunction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak_Statics
	{
		struct ExportPakPluginBPLibrary_eventMakePak_Parms
		{
			FString path;
			bool bIsIOS;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static void NewProp_bIsIOS_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsIOS;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_path_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_path;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ExportPakPluginBPLibrary_eventMakePak_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ExportPakPluginBPLibrary_eventMakePak_Parms), &Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak_Statics::NewProp_bIsIOS_SetBit(void* Obj)
	{
		((ExportPakPluginBPLibrary_eventMakePak_Parms*)Obj)->bIsIOS = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak_Statics::NewProp_bIsIOS = { UE4CodeGen_Private::EPropertyClass::Bool, "bIsIOS", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ExportPakPluginBPLibrary_eventMakePak_Parms), &Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak_Statics::NewProp_bIsIOS_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak_Statics::NewProp_path_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak_Statics::NewProp_path = { UE4CodeGen_Private::EPropertyClass::Str, "path", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(ExportPakPluginBPLibrary_eventMakePak_Parms, path), METADATA_PARAMS(Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak_Statics::NewProp_path_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak_Statics::NewProp_path_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak_Statics::NewProp_bIsIOS,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak_Statics::NewProp_path,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak_Statics::Function_MetaDataParams[] = {
		{ "Category", "myExportPakBpPlugin" },
		{ "ModuleRelativePath", "Public/ExportPakPluginBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UExportPakPluginBPLibrary, "MakePak", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(ExportPakPluginBPLibrary_eventMakePak_Parms), Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UExportPakPluginBPLibrary_NoRegister()
	{
		return UExportPakPluginBPLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UExportPakPluginBPLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UExportPakPluginBPLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_ExportPakPlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UExportPakPluginBPLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UExportPakPluginBPLibrary_CookContent, "CookContent" }, // 471637211
		{ &Z_Construct_UFunction_UExportPakPluginBPLibrary_ExportPakPluginSampleFunction, "ExportPakPluginSampleFunction" }, // 3262640895
		{ &Z_Construct_UFunction_UExportPakPluginBPLibrary_MakePak, "MakePak" }, // 1895399433
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UExportPakPluginBPLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ExportPakPluginBPLibrary.h" },
		{ "ModuleRelativePath", "Public/ExportPakPluginBPLibrary.h" },
		{ "ToolTip", "*      Function library class.\n*      Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*      When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*      BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*      BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*      DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*                              Its lets you name the node using characters not allowed in C++ function names.\n*      CompactNodeTitle - the word(s) that appear on the node.\n*      Keywords -      the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu.\n*                              Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*      Category -      the category your node will be under in the Blueprint drop-down menu.\n*\n*      For more info on custom blueprint nodes visit documentation:\n*      https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UExportPakPluginBPLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UExportPakPluginBPLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UExportPakPluginBPLibrary_Statics::ClassParams = {
		&UExportPakPluginBPLibrary::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UExportPakPluginBPLibrary_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UExportPakPluginBPLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UExportPakPluginBPLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UExportPakPluginBPLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UExportPakPluginBPLibrary, 3146240247);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UExportPakPluginBPLibrary(Z_Construct_UClass_UExportPakPluginBPLibrary, &UExportPakPluginBPLibrary::StaticClass, TEXT("/Script/ExportPakPlugin"), TEXT("UExportPakPluginBPLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UExportPakPluginBPLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
