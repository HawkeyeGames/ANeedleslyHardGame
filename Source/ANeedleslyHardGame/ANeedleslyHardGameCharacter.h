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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		APlatformer_CameraActor* NewCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UParticleSystemComponent* DeathParticle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bCanJump = true;

	void TestForJump();

	bool bCanUseLife = false;
	int Lives = 3;
};
