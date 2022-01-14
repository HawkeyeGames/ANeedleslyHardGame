// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "MovingPlatform.generated.h"

UCLASS()
class ANEEDLESLYHARDGAME_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* PlatformMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bCanMove = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MoveAmount = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MoveDelay = 0.f;
};
