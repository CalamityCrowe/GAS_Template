// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GAS/Attributes/GGHealthSet.h"
#include "GAS/Attributes/GGStatsSet.h"
/**
 * 
 */
struct FSimpleDamageStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Strength);
	DECLARE_ATTRIBUTE_CAPTUREDEF(Defence);

	FSimpleDamageStatics()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGGStatsSet, Strength, Source, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGGStatsSet, Defence, Target, false);
	}
	static const FSimpleDamageStatics& DamageStatics()
	{
		static FSimpleDamageStatics DmgStatics;
		return DmgStatics;
	}
};
