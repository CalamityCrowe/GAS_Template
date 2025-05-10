// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "../GAS_Template.h"
#include "GGBaseAbility.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATE_API UGGBaseAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = "Ability")
	EAbilityInputID AbilityInputID{ EAbilityInputID::None }; 
public:
	EAbilityInputID GetInputID() const { return AbilityInputID; }
};
