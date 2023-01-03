// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ViewportWorldInteraction.h"
#include "EditorWorldExtension.h"
#include "LevelEditor.h"
#include "SLevelViewport.h"
#include "Editor.h"

#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ENVIRONMENTDECORATOR_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	static UViewportWorldInteraction* AddViewportWorldInteraction(UWorld* World);

	UFUNCTION(BlueprintCallable)
	static void RemoveViewportWorldInteraction(UWorld* World);

};
