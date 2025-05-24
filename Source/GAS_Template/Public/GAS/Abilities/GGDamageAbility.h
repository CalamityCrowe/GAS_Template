// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GAS/Abilities/GGBaseAbility.h"
#include "GGDamageAbility.generated.h"

class AGGProjectile;
/**
 *
 */
UCLASS()
class GAS_TEMPLATE_API UGGDamageAbility : public UGGBaseAbility
{
	GENERATED_BODY()
public:
	UGGDamageAbility();

	UPROPERTY(BlueprintReadOnly,EditAnywhere, Category = "Ability|Animation")
	TObjectPtr<UAnimMontage> FireMontage;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability|Projectile")
	TSubclassOf<AGGProjectile> ProjectileRef;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
	TSubclassOf<UGameplayEffect> DamageEffect;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability|Projectile")
	float Damage;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability|Projectile")
	float Range;


	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

protected:
	UFUNCTION()
	void OnCancelled(FGameplayTag EventTag, FGameplayEventData EventData);
	UFUNCTION()
	void OnCompleted(FGameplayTag EventTag, FGameplayEventData EventData);
	UFUNCTION()
	void EventReceived(FGameplayTag EventTag, FGameplayEventData EventData);
};
