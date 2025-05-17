// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/GGPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Input/InputData.h"
#include "AbilitySystemComponent.h"

#include "../GAS_Template.h"

#include "Input/InputData.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include <Kismet/KismetMathLibrary.h>

AGGPlayerCharacter::AGGPlayerCharacter()
{
	Camera = CreateOptionalDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SpringArmComponent = CreateOptionalDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	Camera->SetupAttachment(SpringArmComponent);

	SpringArmComponent->TargetArmLength = 300.f;
	SpringArmComponent->bUsePawnControlRotation = true;		
	SpringArmComponent->SocketOffset = FVector(60.f, 40.f, 0.f);

}

void AGGPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void AGGPlayerCharacter::SendAbilityLocalInput(const FInputActionValue& Value, int32 InputID)
{
	if (!AbilitySystemComponent) 
	{
#if WITH_EDITOR
		UE_LOG(LogTemp, Warning, TEXT("AbilitySystemComponent is null"));
#endif
		return;
	}
	if (Value.Get<bool>())
	{
		AbilitySystemComponent->AbilityLocalInputPressed(InputID);
	}
	else
	{
		AbilitySystemComponent->AbilityLocalInputReleased(InputID);
	}
}

void AGGPlayerCharacter::Tick(float DeltaTime)
{
}

void AGGPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

	if (PlayerInputComponent)
	{
		if (APlayerController* PC = Cast<APlayerController>(Controller))
		{
			if (ULocalPlayer* LocalPlayer = PC->GetLocalPlayer())
			{
				if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
				{
					InputSystem->AddMappingContext(Inputs->Context, 0); // this is erroring due to not setting the data asset that contains the context, this can be fixed by either setting a null check or actually setting the input
				}
			}
		}
	}

	if (UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		PEI->BindAction(Inputs->Actions[0], ETriggerEvent::Triggered, this, &AGGPlayerCharacter::Move);
		PEI->BindAction(Inputs->Actions[1], ETriggerEvent::Triggered, this, &AGGPlayerCharacter::Look);
		PEI->BindAction(Inputs->Actions[2], ETriggerEvent::Started, this, &ACharacter::Jump);
		PEI->BindAction(Inputs->Actions[2], ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		PEI->BindAction(Inputs->Actions[3], ETriggerEvent::Triggered, this, &AGGPlayerCharacter::FireAbility);
	}
}

void AGGPlayerCharacter::Move(const FInputActionValue& Value)
{
	//FVector2D Input = Value.Get<FVector2D>();
	//FRotator CRot = GetControlRotation();

	//FVector RightVec = UKismetMathLibrary::GetRightVector(FRotator(0, CRot.Yaw, CRot.Roll));
	////RightVec = UKismetMathLibrary::NegateVector(RightVec); // this is to make the player move in the direction of the camera, not the opposite direction	
	//AddMovementInput(RightVec, Input.X);
	//FVector ForwardVec = UKismetMathLibrary::GetForwardVector(FRotator(0, CRot.Yaw, 0));
	////ForwardVec = UKismetMathLibrary::NegateVector(ForwardVec); // this is to make the player move in the direction of the camera, not the opposite direction
	//AddMovementInput(ForwardVec, Input.Y);
	MovementAxis = Value.Get<FVector2D>();
	SendAbilityLocalInput(Value, static_cast<int32>(EAbilityInputID::Confirm)); // this takes the Input action value and sends it to the ability system component
}

void AGGPlayerCharacter::Look(const FInputActionValue& Value)
{
	FVector2D Input = Value.Get<FVector2D>();

	AddControllerYawInput(Input.X);
	AddControllerPitchInput(Input.Y);
}

void AGGPlayerCharacter::FireAbility(const FInputActionValue& Value)
{
	SendAbilityLocalInput(Value, static_cast<int32>(EAbilityInputID::Move)); // this takes the Input action value and sends it to the ability system component
}
