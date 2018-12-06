// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ECurrPlatform : uint8;
#ifdef EXPORTPAKPLUGIN_ExportPakPluginBPLibrary_generated_h
#error "ExportPakPluginBPLibrary.generated.h already included, missing '#pragma once' in ExportPakPluginBPLibrary.h"
#endif
#define EXPORTPAKPLUGIN_ExportPakPluginBPLibrary_generated_h

#define make_pak_Plugins_ExportPakPlugin_Source_ExportPakPlugin_Public_ExportPakPluginBPLibrary_h_36_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCookContent) \
	{ \
		P_GET_ENUM(ECurrPlatform,Z_Param_CurrPlatform); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UExportPakPluginBPLibrary::CookContent(ECurrPlatform(Z_Param_CurrPlatform)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMakePak) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_path); \
		P_GET_UBOOL(Z_Param_bIsIOS); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UExportPakPluginBPLibrary::MakePak(Z_Param_path,Z_Param_bIsIOS); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execExportPakPluginSampleFunction) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Param); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=UExportPakPluginBPLibrary::ExportPakPluginSampleFunction(Z_Param_Param); \
		P_NATIVE_END; \
	}


#define make_pak_Plugins_ExportPakPlugin_Source_ExportPakPlugin_Public_ExportPakPluginBPLibrary_h_36_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCookContent) \
	{ \
		P_GET_ENUM(ECurrPlatform,Z_Param_CurrPlatform); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UExportPakPluginBPLibrary::CookContent(ECurrPlatform(Z_Param_CurrPlatform)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMakePak) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_path); \
		P_GET_UBOOL(Z_Param_bIsIOS); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UExportPakPluginBPLibrary::MakePak(Z_Param_path,Z_Param_bIsIOS); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execExportPakPluginSampleFunction) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Param); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=UExportPakPluginBPLibrary::ExportPakPluginSampleFunction(Z_Param_Param); \
		P_NATIVE_END; \
	}


#define make_pak_Plugins_ExportPakPlugin_Source_ExportPakPlugin_Public_ExportPakPluginBPLibrary_h_36_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUExportPakPluginBPLibrary(); \
	friend struct Z_Construct_UClass_UExportPakPluginBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UExportPakPluginBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ExportPakPlugin"), NO_API) \
	DECLARE_SERIALIZER(UExportPakPluginBPLibrary)


#define make_pak_Plugins_ExportPakPlugin_Source_ExportPakPlugin_Public_ExportPakPluginBPLibrary_h_36_INCLASS \
private: \
	static void StaticRegisterNativesUExportPakPluginBPLibrary(); \
	friend struct Z_Construct_UClass_UExportPakPluginBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UExportPakPluginBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ExportPakPlugin"), NO_API) \
	DECLARE_SERIALIZER(UExportPakPluginBPLibrary)


#define make_pak_Plugins_ExportPakPlugin_Source_ExportPakPlugin_Public_ExportPakPluginBPLibrary_h_36_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UExportPakPluginBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UExportPakPluginBPLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UExportPakPluginBPLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UExportPakPluginBPLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UExportPakPluginBPLibrary(UExportPakPluginBPLibrary&&); \
	NO_API UExportPakPluginBPLibrary(const UExportPakPluginBPLibrary&); \
public:


#define make_pak_Plugins_ExportPakPlugin_Source_ExportPakPlugin_Public_ExportPakPluginBPLibrary_h_36_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UExportPakPluginBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UExportPakPluginBPLibrary(UExportPakPluginBPLibrary&&); \
	NO_API UExportPakPluginBPLibrary(const UExportPakPluginBPLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UExportPakPluginBPLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UExportPakPluginBPLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UExportPakPluginBPLibrary)


#define make_pak_Plugins_ExportPakPlugin_Source_ExportPakPlugin_Public_ExportPakPluginBPLibrary_h_36_PRIVATE_PROPERTY_OFFSET
#define make_pak_Plugins_ExportPakPlugin_Source_ExportPakPlugin_Public_ExportPakPluginBPLibrary_h_33_PROLOG
#define make_pak_Plugins_ExportPakPlugin_Source_ExportPakPlugin_Public_ExportPakPluginBPLibrary_h_36_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	make_pak_Plugins_ExportPakPlugin_Source_ExportPakPlugin_Public_ExportPakPluginBPLibrary_h_36_PRIVATE_PROPERTY_OFFSET \
	make_pak_Plugins_ExportPakPlugin_Source_ExportPakPlugin_Public_ExportPakPluginBPLibrary_h_36_RPC_WRAPPERS \
	make_pak_Plugins_ExportPakPlugin_Source_ExportPakPlugin_Public_ExportPakPluginBPLibrary_h_36_INCLASS \
	make_pak_Plugins_ExportPakPlugin_Source_ExportPakPlugin_Public_ExportPakPluginBPLibrary_h_36_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define make_pak_Plugins_ExportPakPlugin_Source_ExportPakPlugin_Public_ExportPakPluginBPLibrary_h_36_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	make_pak_Plugins_ExportPakPlugin_Source_ExportPakPlugin_Public_ExportPakPluginBPLibrary_h_36_PRIVATE_PROPERTY_OFFSET \
	make_pak_Plugins_ExportPakPlugin_Source_ExportPakPlugin_Public_ExportPakPluginBPLibrary_h_36_RPC_WRAPPERS_NO_PURE_DECLS \
	make_pak_Plugins_ExportPakPlugin_Source_ExportPakPlugin_Public_ExportPakPluginBPLibrary_h_36_INCLASS_NO_PURE_DECLS \
	make_pak_Plugins_ExportPakPlugin_Source_ExportPakPlugin_Public_ExportPakPluginBPLibrary_h_36_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class ExportPakPluginBPLibrary."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID make_pak_Plugins_ExportPakPlugin_Source_ExportPakPlugin_Public_ExportPakPluginBPLibrary_h


#define FOREACH_ENUM_ECURRPLATFORM(op) \
	op(ECurrPlatform::Windows) \
	op(ECurrPlatform::IOS) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
