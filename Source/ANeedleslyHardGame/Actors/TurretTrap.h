// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "TurretTrap.generated.h"

UCLASS()
class ANEEDLESLYHARDGAME_API ATurretTrap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurretTrap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		USceneComponent* Root;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* Neck;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* Gun;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UBoxComponent* TriggerBox;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bCanTrigger = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bTriggered = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector EndLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 TriggerChanceMax = 40;

	UFUNCTION(BlueprintCallable)
		void Shoot();

};
