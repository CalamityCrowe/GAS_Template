// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffectTypes.h"
#include "GGBaseCharacter.generated.h"

// forward declarations
class UAbilitySystemComponent;
class UGGHealthSet;
class UGGBaseAbility;
class UGameplayEffect;

UCLASS()
class GAS_TEMPLATE_API AGGBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGGBaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystemComponent; }

	virtual void InitializeAbilities();
	virtual void InitializeEffects();

	virtual void PostInitializeComponents() override;

	virtual void OnDamageTakenChanged(AActor* EffectInstigator, AActor* DamageCauser, const FGameplayTagContainer& GameplayTagContainer, float Damage);
	UFUNCTION(BLueprintImplementableEvent, Category = "GAS")
	void OnDamageTaken(AActor* EffectInstigator, AActor* DamageCauser, const FGameplayTagContainer& GameplayTagContainer, float Damage);

	virtual void OnHealthAttributeChanged(const FOnAttributeChangeData& Data);
	UFUNCTION(BlueprintImplementableEvent, Category = "GAS")
	void OnHealthChanged(float OldHealth, float NewHealth);

	virtual void OnShieldAttributeChanged(const FOnAttributeChangeData& Data);
	UFUNCTION(BlueprintImplementableEvent, Category = "GAS")
	void OnShieldChanged(float OldShield, float NewShield);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS", meta = (AllowPrivateAccess = true))
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS", meta = (AllowPrivateAccess = true))
	TObjectPtr<UGGHealthSet> HealthSet;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS", meta = (AllowPrivateAccess = true))
	TArray<TSubclassOf<UGGBaseAbility>> DefaultAbilities;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS", meta = (AllowPrivateAccess = true))
	TArray<TSubclassOf<UGameplayEffect>> DefaultEffects;

};
