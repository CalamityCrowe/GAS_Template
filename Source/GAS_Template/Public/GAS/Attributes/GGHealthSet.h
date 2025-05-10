// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GAS/Attributes/GGBaseSet.h"
#include "AbilitySystemComponent.h"
#include "GGHealthSet.generated.h"

// this is a delegate that will be called when the health changes and takes 4 parameters 
DECLARE_MULTICAST_DELEGATE_FourParams(FDamageTakenEvent, AActor* /*Effect Instigator*/, AActor* /*Effect Instigator*/, const FGameplayTagContainer& /*Tags*/, float /*Damage*/);
/**
 * 
 */

UCLASS()
class GAS_TEMPLATE_API UGGHealthSet : public UGGBaseSet
{
	GENERATED_BODY()
public:

	UGGHealthSet();

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UGGHealthSet, Health); // this is how to use the Attribute Accessor to give the variable getters and setters
	
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UGGHealthSet, MaxHealth); // this is how to use the Attribute Accessor to give the variable getters and setters
	
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Shield;
	ATTRIBUTE_ACCESSORS(UGGHealthSet, Shield); // this is how to use the Attribute Accessor to give the variable getters and setters
	
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxShield;
	ATTRIBUTE_ACCESSORS(UGGHealthSet, MaxShield); // this is how to use the Attribute Accessor to give the variable getters and setters

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData ShieldRegen;
	ATTRIBUTE_ACCESSORS(UGGHealthSet, ShieldRegen); // this is how to use the Attribute Accessor to give the variable getters and setters

	UPROPERTY(BLueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData InDamage;
	ATTRIBUTE_ACCESSORS(UGGHealthSet, InDamage); // this is how to use the Attribute Accessor to give the variable getters and setters

	mutable FDamageTakenEvent OnDamageTaken; // this is the delegate that will be called when the health changes

protected:
	virtual void ClampAttributeOnChange(const FGameplayAttribute& Attribute, float& NewValue) const override;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

};
