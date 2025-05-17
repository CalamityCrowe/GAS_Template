// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/GGBaseCharacter.h"
#include "GGPlayerCharacter.generated.h"

/**
 * 
 */
class UCameraComponent;
class USpringArmComponent;
class UInputData;
UCLASS()
class GAS_TEMPLATE_API AGGPlayerCharacter : public AGGBaseCharacter
{
	GENERATED_BODY()
	
public:
	AGGPlayerCharacter();

protected:
	virtual void BeginPlay() override;

	virtual void SendAbilityLocalInput(const FInputActionValue& Value, int32 InputID);

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	UFUNCTION()
	virtual void Move(const FInputActionValue& Value); 
	UFUNCTION()
	virtual void Look(const FInputActionValue& Value);

	virtual void FireAbility(const FInputActionValue& Value);

private:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = true))
	TObjectPtr<UCameraComponent> Camera;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = true))
	TObjectPtr<USpringArmComponent> SpringArmComponent;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = true))
	TObjectPtr<UInputData> Inputs;

};
