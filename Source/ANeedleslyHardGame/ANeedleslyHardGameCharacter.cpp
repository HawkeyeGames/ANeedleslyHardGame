// Copyright Epic Games, Inc. All Rights Reserved.

#include "ANeedleslyHardGameCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"

AANeedleslyHardGameCharacter::AANeedleslyHardGameCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	DeathParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Death particle"));
	DeathParticle->SetupAttachment(RootComponent);

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

void AANeedleslyHardGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsPlaying)
	{
		GetController()->SetIgnoreMoveInput(false);
		bCanJump = true;
	}
	else
	{
		GetController()->SetIgnoreMoveInput(true);
		bCanJump = false;
	}

	if (IsJumping)
	{
		if (JumpHeight >= MaxJumpHeight)
		{
			return;
		}
		else
		{
			JumpHeight += 50.f;
		}
		
		GetCharacterMovement()->JumpZVelocity = JumpHeight;

		UE_LOG(LogTemp, Warning, TEXT("Jump height is set to %s"), *FString::SanitizeFloat(GetCharacterMovement()->JumpZVelocity));
	}
	else
	{
		JumpHeight = 600.f;
		GetCharacterMovement()->JumpZVelocity = JumpHeight;
	}
}


//////////////////////////////////////////////////////////////////////////
// Input

void AANeedleslyHardGameCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AANeedleslyHardGameCharacter::TestForJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AANeedleslyHardGameCharacter::TestForJumpNot);
	PlayerInputComponent->BindAxis("MoveRight", this, &AANeedleslyHardGameCharacter::MoveRight);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &AANeedleslyHardGameCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AANeedleslyHardGameCharacter::TouchStopped);
}

void AANeedleslyHardGameCharacter::MoveRight(float Value)
{
	// add movement in that direction
	AddMovementInput(FVector(0.f,-1.f,0.f), Value);
}

void AANeedleslyHardGameCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// jump on any touch
	if (bCanJump)
	{
		IsJumping = true;
		Jump();
	}
}

void AANeedleslyHardGameCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	IsJumping = false;
	StopJumping();
}

void AANeedleslyHardGameCharacter::TestForJump()
{
	if (bDead) return;
	
	int32 JumpChance;

	if (bAtEnd)
	{
		JumpChance = FMath::RandRange(1, 5);
	}
	else
	{
		JumpChance = FMath::RandRange(1, 10);
	}

	if (JumpChance == 1)
	{
		bCanJump = false;
	}
	else
	{
		bCanJump = true;
	}

	if (bCanJump)
	{
		IsJumping = true;

		float JumpDelay = FMath::FRandRange(0.005f, 0.2f);

		GetWorldTimerManager().SetTimer(JumpDelayHandle, this, &AANeedleslyHardGameCharacter::JumpDelay, JumpDelay, false, JumpDelay);
	}
}

void AANeedleslyHardGameCharacter::TestForJumpNot()
{
	IsJumping = false;
	StopJumping();
}

void AANeedleslyHardGameCharacter::JumpDelay()
{
	Jump();
}