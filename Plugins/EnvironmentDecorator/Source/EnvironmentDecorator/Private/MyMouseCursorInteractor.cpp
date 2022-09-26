// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMouseCursorInteractor.h"

class UWorld* UMyMouseCursorInteractor::GetWorld() const
{
	return WorldInteraction ? WorldInteraction->GetWorld() : NULL;
}

void UMyMouseCursorInteractor::AddKeyInputAction(FName ActionName, FKey Key)
{
	AddKeyAction(Key, ActionName);
}