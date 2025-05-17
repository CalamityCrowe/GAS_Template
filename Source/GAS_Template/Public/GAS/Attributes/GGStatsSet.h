// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GAS/Attributes/GGBaseSet.h"
#include "AbilitySystemComponent.h"
#include "GGStatsSet.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATE_API UGGStatsSet : public UGGBaseSet
{
	GENERATED_BODY()
public:
	UGGStatsSet();

	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Stats", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UGGStatsSet, Strength); // this is how to use the Attribute Accessor to give the variable getters and setters
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Stats", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Defence;
	ATTRIBUTE_ACCESSORS(UGGStatsSet, Defence); // this is how to use the Attribute Accessor to give the variable getters and setters
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Stats", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Magic;
	ATTRIBUTE_ACCESSORS(UGGStatsSet, Magic); // this is how to use the Attribute Accessor to give the variable getters and setters
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Stats", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MagicDefence;
	ATTRIBUTE_ACCESSORS(UGGStatsSet, MagicDefence); // this is how to use the Attribute Accessor to give the variable getters and setters
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Stats", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Agility;
	ATTRIBUTE_ACCESSORS(UGGStatsSet, Agility); // this is how to use the Attribute Accessor to give the variable getters and setters
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Stats", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Evasion;
	ATTRIBUTE_ACCESSORS(UGGStatsSet, Evasion); // this is how to use the Attribute Accessor to give the variable getters and setters
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Stats", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Accuracy;
	ATTRIBUTE_ACCESSORS(UGGStatsSet, Accuracy); // this is how to use the Attribute Accessor to give the variable getters and setters
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Stats", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Luck;
	ATTRIBUTE_ACCESSORS(UGGStatsSet, Luck); // this is how to use the Attribute Accessor to give the variable getters and setters

protected:
	virtual void ClampAttributeOnChange(const FGameplayAttribute& Attribute, float& NewValue) const override;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};
