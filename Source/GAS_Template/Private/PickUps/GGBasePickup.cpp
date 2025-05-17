// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUps/GGBasePickup.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Characters/GGBaseCharacter.h"
#include "AbilitySystemComponent.h"

// Sets default values
AGGBasePickup::AGGBasePickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Collider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	Collider->SetCollisionProfileName(TEXT("OverlapAll"));
	SetRootComponent(Collider);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Collider);

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

	Collider->OnComponentBeginOverlap.AddDynamic(this, &AGGBasePickup::OnBeginOverlap);
}

// Called when the game starts or when spawned
void AGGBasePickup::BeginPlay()
{
	Super::BeginPlay();
	InitializeEffects();
}

void AGGBasePickup::InitializeEffects()
{
	if (!AbilitySystemComponent)
	{
		return; 
	}
	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);
	for (TSubclassOf<UGameplayEffect>& Effect : DefaultEffects)
	{
		FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(Effect, 1, EffectContext);
		if (SpecHandle.IsValid())
		{
			FActiveGameplayEffectHandle ActiveHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		}
	}
}

// Called every frame
void AGGBasePickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGGBasePickup::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AGGBaseCharacter* temp = Cast<AGGBaseCharacter>(OtherActor))
	{
			if (EffectToApply)
			{
				FGameplayEffectContextHandle EffectContext = temp->GetAbilitySystemComponent()->MakeEffectContext();
				EffectContext.AddSourceObject(this);
				FGameplayEffectSpecHandle SpecHandle = temp->GetAbilitySystemComponent()->MakeOutgoingSpec(EffectToApply, 1, EffectContext);
				if (SpecHandle.IsValid())
				{
					FActiveGameplayEffectHandle ActiveHandle = temp->GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
					Destroy();
				}
			}
	}
}


