// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ExportPakPluginBPLibrary.h"
#include "ExportPakPlugin.h"

#include "MyExportPak.h"

UExportPakPluginBPLibrary::UExportPakPluginBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UExportPakPluginBPLibrary::ExportPakPluginSampleFunction(float Param)
{
	return -1;
}

bool UExportPakPluginBPLibrary::MakePak(const FString& path, bool bIsIOS)
{
	UMyExportPak* MakePakInst = NewObject<UMyExportPak>();
	MakePakInst->ClickMakePak(path, bIsIOS);
	return true;
}

void UExportPakPluginBPLibrary::CookContent(ECurrPlatform CurrPlatform)
{
	UMyExportPak* MakePakInst = NewObject<UMyExportPak>();
	switch (CurrPlatform)
	{
		case ECurrPlatform::Windows:
		{
			MakePakInst->TestCook(FName(TEXT("Windows")));
			break;
		}
		case ECurrPlatform::IOS:
		{
			MakePakInst->TestCook(FName(TEXT("IOS")));
			break;
		}
	}
	
}