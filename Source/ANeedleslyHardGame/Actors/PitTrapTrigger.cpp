// Fill out your copyright notice in the Description page of Project Settings.


#include "ANeedleslyHardGame/Actors/PitTrapTrigger.h"

// Sets default values
APitTrapTrigger::APitTrapTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root component"));
	RootComponent = Root;

	PitMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pit mesh component"));
	PitMesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void APitTrapTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APitTrapTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

