// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile/GGProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
// Sets default values
AGGProjectile::AGGProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
}

// Called when the game starts or when spawned
void AGGProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}


