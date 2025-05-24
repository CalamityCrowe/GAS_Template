// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Abilities/GGBaseAbility.h"
#include "AbilitySystemComponent.h"
#include "GameplayTagContainer.h "

UGGBaseAbility::UGGBaseAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;


	// these tags will stop the ability from activating
	ActivationBlockedTags.AddTag(FGameplayTag::RequestGameplayTag(FName("State.Dead")));
	ActivationBlockedTags.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability.Cooldown")));

	// these tags will allow the ability to activate if it is not on cooldown
	//ActivationRequiredTags.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability.Ready")));
}

void UGGBaseAbility::OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnAvatarSet(ActorInfo, Spec);

	if (bActivateAbilityOnGranted)
	{
		ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle, false);
	}
}

