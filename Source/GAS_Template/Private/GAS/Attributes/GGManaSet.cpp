// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Attributes/GGManaSet.h"
#include "GameplayEffectExtension.h"
UGGManaSet::UGGManaSet() : MP(0.f), MaxMP(100.f), InManaCost(0.f)
{
}

void UGGManaSet::ClampAttributeOnChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	if(Attribute == GetMPAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxMP());
	}
	if (Attribute == GetMaxMPAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, FLT_MAX);
	}
}

void UGGManaSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	if (Data.EvaluatedData.Attribute == GetInManaCostAttribute())
	{
		float InManaCostDone = GetInManaCost();
		SetInManaCost(0.f); // reset the in damage to 0 after it has been used
		if (InManaCostDone > 0.0f)
		{
			const float NewMP = GetMP() - InManaCostDone;
			SetMP(NewMP);
		}
	}
}
