// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "GGBaseCostCalculation.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATE_API UGGBaseCostCalculation : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
	
public:

	float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override; 
};
