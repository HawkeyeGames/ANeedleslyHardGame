// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DisasterPlate.generated.h"

UENUM()
enum DisasterType
{
	Earthquake	UMETA(DisplayName = "Earthquake"),
	Thanos	UMETA(DisplayName = "Thanos Snap"),
	Charles	UMETA(DisplayName = "Charles"),
	Nuke	UMETA(DisplayName = "Nukelear Bomb"),
	Meteor	UMETA(DisplayName = "Meteor"),
};

UCLASS()
class ANEEDLESLYHARDGAME_API ADisasterPlate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADisasterPlate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		USceneComponent* Root;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* Plate;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bCanTrigger = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<DisasterType> Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector PlayerStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bTriggered = false;

	UFUNCTION()
		void TouchedPlate(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION(BlueprintImplementableEvent)
		void TriggerDisaster();
};
