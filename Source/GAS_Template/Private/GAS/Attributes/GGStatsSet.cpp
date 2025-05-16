// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Attributes/GGStatsSet.h"

UGGStatsSet::UGGStatsSet() :Strength(1.0f), Defence(1.0f), Magic(1.0f), MagicDefence(1.0f), Agility(1.0f), Evasion(1.0f), Accuracy(1.0f), Luck(1.0f)
{
}

void UGGStatsSet::ClampAttributeOnChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	// this is getting setup later
}

void UGGStatsSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	// this is getting setup later
}
