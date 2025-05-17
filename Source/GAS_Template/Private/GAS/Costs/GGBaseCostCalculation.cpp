// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Costs/GGBaseCostCalculation.h"
#include "GAS/Abilities/GGBaseAbility.h"
	
float UGGBaseCostCalculation::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const UGGBaseAbility* Ability = Cast<UGGBaseAbility>(Spec.GetContext().GetAbility());

	if (Ability)
	{
		return Ability->Cost;
	}
	return 0.f;
}