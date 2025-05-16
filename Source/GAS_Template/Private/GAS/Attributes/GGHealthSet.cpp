// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Attributes/GGHealthSet.h"
#include "GameplayEffectExtension.h"


UGGHealthSet::UGGHealthSet() 
{
}

/// <summary>
///  This function checks the attribute that is passed in on call against the attributes in the set.
/// 
/// The attributes made using the ATTRIBUTE_ACCESSORS to create the getter and setters.
/// 
/// if it equals the health attribute then it will clamp the value to be between 0 and max health.
/// 
/// if it is not then it will move onto the next attribute till it gets to the correct attribute or the end of the function
/// </summary>
/// <param name="Attribute"></param>
/// <param name="NewValue"></param>
void UGGHealthSet::ClampAttributeOnChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	if(Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
	}
	else if(Attribute == GetShieldAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxShield());
	}
}

/// <summary>
///  this decides what to do when the gameplay effect is executed.
/// 
/// in this situation, it checks if the attribute that was changed is the in damage attribute.
/// 
/// if it is then it will get the value of the in damage attribute and then start to check if the damage is greater than 0. and execute the relevant effects, like signaling delegates
/// </summary>
/// <param name="Data"></param>
void UGGHealthSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	if (Data.EvaluatedData.Attribute == GetInDamageAttribute()) 
	{
		float InDamageDone = GetInDamage();
		SetInDamage(0.f); // reset the in damage to 0 after it has been used
		if (InDamageDone > 0.0f) 
		{
			if (OnDamageTaken.IsBound()) 
			{
				const FGameplayEffectContextHandle& EffectContext = Data.EffectSpec.GetContext();
				AActor* Instigator = EffectContext.GetOriginalInstigator();
				AActor* DamageCauser = EffectContext.GetEffectCauser();

				OnDamageTaken.Broadcast(Instigator, DamageCauser, Data.EffectSpec.CapturedSourceTags.GetSpecTags(), InDamageDone);
			}
			if (GetShield() > 0.0f) 
			{
				const float NewShield = GetShield() - InDamageDone;
				SetShield(NewShield);
				InDamageDone = FMath::Clamp(InDamageDone, 0.0f, GetShield());
			}
			if (InDamageDone > 0.0f && GetHealth() > 0.0f) 
			{
				const float NewHealth = GetHealth() - InDamageDone;
				SetHealth(NewHealth);
			}
		}
	}
}
