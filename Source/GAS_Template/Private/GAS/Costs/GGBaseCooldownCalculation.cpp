// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Costs/GGBaseCooldownCalculation.h"
#include "GAS/Abilities/GGBaseAbility.h"

float UGGBaseCooldownCalculation::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const UGGBaseAbility* Ability = Cast<UGGBaseAbility>(Spec.GetEffectContext().GetAbility());
	if(Ability)
	{
		return Ability->CooldownDuration;
	}
    return 0.0f;
}
