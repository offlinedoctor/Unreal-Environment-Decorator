// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"

UViewportWorldInteraction* UMyBlueprintFunctionLibrary::AddViewportWorldInteraction(UWorld* World)
{
	UEditorWorldExtensionCollection* ExtensionCollection = GEditor->GetEditorWorldExtensionsManager()->GetEditorWorldExtensions(World);
	check(ExtensionCollection != nullptr);

	UViewportWorldInteraction* ViewportWorldInteraction = Cast<UViewportWorldInteraction>(ExtensionCollection->AddExtension(UViewportWorldInteraction::StaticClass()));
	check(ViewportWorldInteraction != nullptr);

	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	const TSharedRef<ILevelEditor>& LevelEditor = LevelEditorModule.GetFirstLevelEditor().ToSharedRef();

	TSharedPtr<FEditorViewportClient>ViewportClient;
	{
		TSharedPtr<IAssetViewport> ActiveLevelViewport = LevelEditor->GetActiveViewportInterface();
		if (ActiveLevelViewport.IsValid())
		{
			ViewportClient = StaticCastSharedRef<SLevelViewport>(ActiveLevelViewport->AsWidget())->GetViewportClient();
		}
	}

	ViewportWorldInteraction->SetDefaultOptionalViewportClient(ViewportClient);

	return ViewportWorldInteraction;

}

void UMyBlueprintFunctionLibrary::RemoveViewportWorldInteraction(UWorld* World)
{
	UEditorWorldExtensionCollection* ExtensionCollection = GEditor->GetEditorWorldExtensionsManager()->GetEditorWorldExtensions(World);
	check(ExtensionCollection != nullptr);

	if (UEditorWorldExtension* WorldExtension = ExtensionCollection->FindExtension(UViewportWorldInteraction::StaticClass()))
	{
		ExtensionCollection->RemoveExtension(WorldExtension);
	}
	
	
}