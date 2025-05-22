// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GAS/Abilities/GGBaseAbility.h"
#include "GGDamageAbility.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATE_API UGGDamageAbility : public UGGBaseAbility
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability|Damage")
	double DamageConstant = 16;
	UFUNCTION(BlueprintPure)
	float DamageCalculation(float Stat);
	UFUNCTION(BlueprintPure)
	int DamageReduction(float BaseDamage, float DefenceStat);

	UFUNCTION(BlueprintPure)
	int FinalDamageCalculation(float Stat, float DefenceStat); 
};
