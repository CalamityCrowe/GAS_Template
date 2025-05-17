// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EAbilityInputID:uint8
{ 
	None UMETA(DisplayName = "None"),
	Confirm UMETA(DisplayName = "Confirm"),
	Cancel UMETA(DisplayName = "Cancel"),
	FireAbility UMETA(DisplayName  = "FireAbility"),
	Move UMETA(DisplayName  = "Move"), 
	Look UMETA(DisplayName  = "Look")
};