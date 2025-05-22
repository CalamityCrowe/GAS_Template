// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Calculations/GGBaseEffectCalculation.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffectAttributeCaptureDefinition.h"

const FSimpleDamageStatics* UGGBaseEffectCalculation::DamageStatics = nullptr;

UGGBaseEffectCalculation::UGGBaseEffectCalculation()
{
	if (DamageStatics == nullptr)
	{
		DamageStatics = &FSimpleDamageStatics::DamageStatics();
	}

	RelevantAttributesToCapture.Add(DamageStatics->StrengthDef);
	RelevantAttributesToCapture.Add(DamageStatics->DefenceDef);
}

void UGGBaseEffectCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);

	// checks if the damage statics are initialized, if not it will attempt to make it and assign it. if it fails it will return.
	if(!DamageStatics) 
	{
		DamageStatics = &FSimpleDamageStatics::DamageStatics();
	}
	if (!DamageStatics)
	{
		return;
	}

	// grabs the target ability system component from the execution parameters and checks if it is valid. if not it will return.
	UAbilitySystemComponent* const TargetAbilitySystemComponent = Cast<UAbilitySystemComponent>(ExecutionParams.GetTargetAbilitySystemComponent());
	if(TargetAbilitySystemComponent == nullptr) 
	{
		return;
	}
	// same as before, but with the source instead
	UAbilitySystemComponent* const SourceAbilitySystemComponent = Cast<UAbilitySystemComponent>(ExecutionParams.GetSourceAbilitySystemComponent());
	if (SourceAbilitySystemComponent == nullptr)
	{
		return;
	}

	AActor* const SourceActor = SourceAbilitySystemComponent ? SourceAbilitySystemComponent->GetAvatarActor() : nullptr;
	AActor* const TargetActor = TargetAbilitySystemComponent ? TargetAbilitySystemComponent->GetAvatarActor() : nullptr;

	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();
	FAggregatorEvaluateParameters EvaluationParameters{};
	EvaluationParameters.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	EvaluationParameters.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	float SourceStrength = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics->StrengthDef, EvaluationParameters, SourceStrength);
	SourceStrength = FMath::Max(SourceStrength, 0.f);

	float BaseDamage = 0.f;
	BaseDamage = FMath::Pow(SourceStrength, 3) / 32;
	BaseDamage += 32;
	BaseDamage *= (DamageConstant / 16.f);

	float TargetDefence = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics->DefenceDef, EvaluationParameters, TargetDefence);
	TargetDefence = FMath::Pow(FMath::RoundToZero(TargetDefence - 280.4), 2) / 110;
	TargetDefence += 16;
	int DefInt = FMath::RoundToInt(TargetDefence);
	BaseDamage = BaseDamage * DefInt;
	BaseDamage /= 730.f;


	const float FinalDamage = SourceStrength * 2.f; // Example calculation, replace with your own logic
}
