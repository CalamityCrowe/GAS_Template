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
}

// Called when the game starts or when spawned
void AGGBasePickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGGBasePickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGGBasePickup::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if(AGGBaseCharacter* temp = Cast<AGGBaseCharacter>(OtherActor))
	{
		for (TSubclassOf<UGameplayEffect>& Effect : DefaultEffects)
		{
			if (Effect)
			{
				FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(Effect, 1, AbilitySystemComponent->MakeEffectContext());
				if (SpecHandle.IsValid()) 
				{
					FActiveGameplayEffectHandle ActiveHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), temp->GetAbilitySystemComponent());
				}
			}
		}
	}
}

