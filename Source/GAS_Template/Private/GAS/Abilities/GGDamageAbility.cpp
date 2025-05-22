// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Abilities/GGDamageAbility.h"

float UGGDamageAbility::DamageCalculation(float Stat)
{
	if (Stat < 0)
	{
		return 0;
	}
	float Damage  = FMath::Pow(Stat,3)/32; 
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Damage: %f"), Damage));
	Damage += 32;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Damage: %f"), Damage));
	Damage *= (DamageConstant / 16.f); 
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Damage: %f"), Damage));
	return Damage;
}

int UGGDamageAbility::DamageReduction(float BaseDamage, float DefenceStat)
{
	DefenceStat = (FMath::Pow(DefenceStat - 280.4, 2) / 110);
	DefenceStat += 16; 
	int DefInt = FMath::RoundToInt(DefenceStat);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Defence: %d"), DefInt));
	return DefInt;
}

int UGGDamageAbility::FinalDamageCalculation(float Stat, float DefenceStat)
{
	return 0;
}

