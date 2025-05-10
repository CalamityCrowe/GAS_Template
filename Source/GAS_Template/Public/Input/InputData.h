// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputData.generated.h"

// forward declarations
class UInputAction;
class UInputMappingContext;

/**
 * 
 */
UCLASS()
class GAS_TEMPLATE_API UInputData : public UDataAsset
{
	GENERATED_BODY()
public:
	UInputData();
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inputs|Contexts")
	TObjectPtr<UInputMappingContext> Context;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inputs|Movement")
	TArray<TObjectPtr<UInputAction>> Actions;
};
