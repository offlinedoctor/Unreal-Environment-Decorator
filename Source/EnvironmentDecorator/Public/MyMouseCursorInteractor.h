// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MouseCursorInteractor.h"
#include "ViewportWorldInteraction.h"
#include "MyMouseCursorInteractor.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ENVIRONMENTDECORATOR_API UMyMouseCursorInteractor : public UMouseCursorInteractor
{
	GENERATED_BODY()
	
public:
	class UWorld* GetWorld() const override;


	//NEW STUFF
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	//void OnInteractorsInitilization();

	//NEW STUFF
	UFUNCTION(BlueprintCallable)
	void AddKeyInputAction(FName ActionName, FKey Key);

	//Key's are part of the InputCore module (put this in the plugins public dependency module)


};
