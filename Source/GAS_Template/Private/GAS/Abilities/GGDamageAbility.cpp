// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Abilities/GGDamageAbility.h"

UGGDamageAbility::UGGDamageAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;

	FGameplayTag Ability1Tag = FGameplayTag::RequestGameplayTag(FName("Ability.Skill.Ability1"));
	AbilityTags.AddTag(Ability1Tag);
	ActivationOwnedTags.AddTag(Ability1Tag);

	ActivationBlockedTags.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability.Skill")));

	Range = 1000.f; // Default range for the projectile
	Damage = 12.f;
}

void UGGDamageAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
}

void UGGDamageAbility::OnCancelled(FGameplayTag EventTag, FGameplayEventData EventData)
{
}

void UGGDamageAbility::OnCompleted(FGameplayTag EventTag, FGameplayEventData EventData)
{
}

void UGGDamageAbility::EventReceived(FGameplayTag EventTag, FGameplayEventData EventData)
{
}
