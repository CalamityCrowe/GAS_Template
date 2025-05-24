// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffect.h"
#include "GGProjectile.generated.h"

class UProjectileMovementComponent;

UCLASS()
class GAS_TEMPLATE_API AGGProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGGProjectile();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	FGameplayEffectSpecHandle DamageEffectSpecHandle;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = true, AllowPrivateAccess = true))
	float Range; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent;

};
