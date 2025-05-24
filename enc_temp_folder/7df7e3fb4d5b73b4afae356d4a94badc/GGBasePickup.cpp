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

}

// Called when the game starts or when spawned
void AGGBasePickup::BeginPlay()
{
	Super::BeginPlay();
	if(PickupEffect)
	{
		//FGameplayEffectSpecHandle PickupEffectSpecHandle = MakeOutgoingSpec(PickupEffect, 1.0f, GetAbilitySystemComponent()->MakeEffectContext());
	}

}



// Called every frame
void AGGBasePickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




