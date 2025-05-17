// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GAS/Attributes/GGBaseSet.h"
#include "AbilitySystemComponent.h"
#include "GGMovementSet.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATE_API UGGMovementSet : public UGGBaseSet
{
	GENERATED_BODY()
protected:
	UGGMovementSet();
	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;
	virtual void ClampAttributeOnChange(const FGameplayAttribute& Attribute, float& NewValue) const;

	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Movement", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MovementSpeedMultiplier;
	ATTRIBUTE_ACCESSORS(UGGMovementSet, MovementSpeedMultiplier); // this is how to use the Attribute Accessor to give the variable getters and setters
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Movement", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MovementAccelerationMultiplier;
	ATTRIBUTE_ACCESSORS(UGGMovementSet, MovementAccelerationMultiplier); // this is how to use the Attribute Accessor to give the variable getters and setters

protected:



};
