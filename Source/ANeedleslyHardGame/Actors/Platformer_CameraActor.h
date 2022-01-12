// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "Platformer_CameraActor.generated.h"

UCLASS()
class ANEEDLESLYHARDGAME_API APlatformer_CameraActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformer_CameraActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		AActor* SectionEnd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Offset = 2000;

	FVector AvgLoc;
};
