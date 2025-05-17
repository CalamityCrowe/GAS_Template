// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GAS/Attributes/GGBaseSet.h"
#include "AbilitySystemComponent.h"
#include "GGManaSet.generated.h"

//DECLARE_MULTICAST_DELEGATE_FourParams(FManaCostEvent, AActor* /*Effect Instigator*/, AActor* /*Effect Instigator*/, const FGameplayTagContainer& /*Tags*/, float /*Damage*/);


/**
 * 
 */
UCLASS()
class GAS_TEMPLATE_API UGGManaSet : public UGGBaseSet
{
	GENERATED_BODY()
public:
	UGGManaSet();

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MP;
	ATTRIBUTE_ACCESSORS(UGGManaSet, MP); // this is how to use the Attribute Accessor to give the variable getters and setters

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxMP;
	ATTRIBUTE_ACCESSORS(UGGManaSet, MaxMP); // this is how to use the Attribute Accessor to give the variable getters and setters

	UPROPERTY(BLueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData InManaCost;
	ATTRIBUTE_ACCESSORS(UGGManaSet, InManaCost); // this is how to use the Attribute Accessor to give the variable getters and setters
	 
	//mutable FManaCostEvent OnManaCost; // this is the delegate that will be called when the health changes

protected:
	virtual void ClampAttributeOnChange(const FGameplayAttribute& Attribute, float& NewValue) const override;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};
