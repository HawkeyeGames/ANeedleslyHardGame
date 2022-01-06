// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "SpikeTrap.generated.h"

UCLASS()
class ANEEDLESLYHARDGAME_API ASpikeTrap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpikeTrap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		USceneComponent* Root;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UBoxComponent* Trigger;

	UFUNCTION(BlueprintCallable)
	void OnTriggered();

	UFUNCTION()
	void TimerEnd();

	UPROPERTY(BlueprintReadOnly)
	bool bCanTrigger = true;
	
	UPROPERTY(BlueprintReadWrite)
	bool bOverlappingTrap = false;

	FTimerHandle Timer;

	FVector StartLoc;

};
