// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Attributes/GGMovementSet.h"

UGGMovementSet::UGGMovementSet() :MovementAccelerationMultiplier(1.f), MovementSpeedMultiplier(1.f)
{
}

void UGGMovementSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::PreAttributeBaseChange(Attribute, NewValue);	

	NewValue = 1.f; // this is the default value for all attributes
}

void UGGMovementSet::ClampAttributeOnChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::ClampAttributeOnChange(Attribute, NewValue);

	NewValue = FMath::Max(NewValue, 0); 
}
