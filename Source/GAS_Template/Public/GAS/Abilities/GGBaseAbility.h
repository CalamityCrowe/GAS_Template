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
	

public:

	UGGBaseAbility();
	UPROPERTY(EditAnywhere, Category = "Ability")
	EAbilityInputID AbilityInputID{ EAbilityInputID::None }; 
	UPROPERTY(EditAnywhere, Category = "Ability")
	EAbilityInputID AbilityID{ EAbilityInputID::None };

	
	UPROPERTY(EditAnywhere, Category = "Ability")
	bool bActivateAbilityOnGranted = false; // If true, the ability will be activated immediately when granted. Useful for passive abilities.


	UPROPERTY(EditDefaultsOnly, Category = "Ability")
	float Cost; 
	UPROPERTY(EditDefaultsOnly, Category = "Ability")
	float CooldownDuration;
	

	virtual void OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;

};
