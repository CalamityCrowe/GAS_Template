// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GAS/Calculations/SimpleDamageStatics.h"
#include "GGBaseEffectCalculation.generated.h"



/**
 * 
 */
UCLASS()
class GAS_TEMPLATE_API UGGBaseEffectCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
protected:
	static const FSimpleDamageStatics* DamageStatics;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GAS|Constant", meta = (AllowPrivateAccess = true))
	float DamageConstant = 1.0f; // This is a constant that can be used to modify the damage calculation. It is set to 1.0f by default.
public:

	UGGBaseEffectCalculation();

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
