// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ANeedleslyHardGame/Actors/Platformer_CameraActor.h"
#include "Particles/ParticleSystemComponent.h"
#include "ANeedleslyHardGameCharacter.generated.h"

UCLASS(config=Game)
class AANeedleslyHardGameCharacter : public ACharacter
{
	GENERATED_BODY()

protected:

	/** Called for side to side input */
	void MoveRight(float Val);

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface


public:
	AANeedleslyHardGameCharacter();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		APlatformer_CameraActor* NewCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UParticleSystemComponent* DeathParticle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bCanJump = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bDead = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bAtEnd = false;

	void TestForJump();
	void TestForJumpNot();

	UPROPERTY(BlueprintReadWrite)
		bool IsJumping = false;

	float JumpHeight = 600.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxJumpHeight = 1100.f;

	bool bCanUseLife = false;
	int32 Lives = 3;

	FTimerHandle JumpDelayHandle;
	void JumpDelay();
};
