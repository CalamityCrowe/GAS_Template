// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EAbilityInputID:uint8
{ //0 = None, 
	None UMETA(DisplayName = "None"),
	//1 = Confirm,
	Confirm UMETA(DisplayName = "Confirm"),
	//2 = Cancel,
	Cancel UMETA(DisplayName = "Cancel"),
	//3 = LMB,
	Ability1 UMETA(DisplayName  = "Ability1"),
	//4 = RMB,
	Ability2 UMETA(DisplayName = "Ability2"),
	//5 = Q,
	Ability3 UMETA(DisplayName = "Ability3"),
	//6 = E,
	Ability4 UMETA(DisplayName = "Ability4"),
	//7 = R,
	Ability5 UMETA(DisplayName = "Ability5"),
	//8 Sprint,
	Sprint UMETA(DisplayName = "Sprint"),


	Move UMETA(DisplayName  = "Move"), 
	Look UMETA(DisplayName  = "Look")
};