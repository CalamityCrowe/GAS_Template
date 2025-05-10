// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/GGBaseCharacter.h"
#include "AbilitySystemComponent.h"
#include "GAS/Attributes/GGHealthSet.h"
#include "GAS/Abilities/GGBaseAbility.h"

// Sets default values
AGGBaseCharacter::AGGBaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

	HealthSet = CreateDefaultSubobject<UGGHealthSet>(TEXT("HealthSet"));
}

// Called when the game starts or when spawned
void AGGBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	HealthSet->OnDamageTaken.AddUObject(this, &AGGBaseCharacter::OnDamageTakenChanged); // think of this as a AddDynamic effectively

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UGGHealthSet::GetHealthAttribute()).AddUObject(this, &AGGBaseCharacter::OnHealthAttributeChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UGGHealthSet::GetShieldAttribute()).AddUObject(this, &AGGBaseCharacter::OnShieldAttributeChanged);
}

void AGGBaseCharacter::InitializeAbilities()
{
	if (!HasAuthority() || !AbilitySystemComponent)
	{
#if WITH_EDITOR
		UE_LOG(LogTemp, Warning, TEXT("AGGBaseCharacter::InitializeAbilities: Not on authority or AbilitySystemComponent is null"));
#endif
		return;
	}
	for(TSubclassOf<UGGBaseAbility>& Ability: DefaultAbilities)
	{
			FGameplayAbilitySpecHandle SpecHandle = AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(Ability, 1, static_cast<int32>(Ability.GetDefaultObject()->GetInputID()), this));
	}
}

void AGGBaseCharacter::InitializeEffects()
{
	if(!AbilitySystemComponent)
	{
#if WITH_EDITOR
		UE_LOG(LogTemp, Warning, TEXT("AGGBaseCharacter::InitializeEffects: AbilitySystemComponent is null"));
#endif
		return;
	}
	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);
	for(TSubclassOf<UGameplayEffect>& Effect:DefaultEffects)
	{
		FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(Effect, 1, EffectContext);
		if (SpecHandle.IsValid()) 
		{
			FActiveGameplayEffectHandle ActiveHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		}
	}
}
void AGGBaseCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	if(!AbilitySystemComponent)
	{
#if WITH_EDITOR
		UE_LOG(LogTemp, Warning, TEXT("AGGBaseCharacter::PostInitializeComponents: AbilitySystemComponent is null"));
#endif
	}
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	InitializeEffects();
	InitializeAbilities();
}

void AGGBaseCharacter::OnDamageTakenChanged(AActor* EffectInstigator, AActor* DamageCauser, const FGameplayTagContainer& GameplayTagContainer, float Damage)
{
	OnDamageTaken(EffectInstigator, DamageCauser, GameplayTagContainer, Damage);
}

void AGGBaseCharacter::OnHealthAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnHealthChanged(Data.OldValue, Data.NewValue);
}

void AGGBaseCharacter::OnShieldAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnShieldChanged(Data.OldValue, Data.NewValue);
}

// Called every frame
void AGGBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGGBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

