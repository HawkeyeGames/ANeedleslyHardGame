// Fill out your copyright notice in the Description page of Project Settings.


#include "ANeedleslyHardGame/Actors/CeilingTrap.h"

// Sets default values
ACeilingTrap::ACeilingTrap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("The root component"));
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("The mesh component"));
	Mesh->SetupAttachment(Root);

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("The trigger component"));
	Trigger->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void ACeilingTrap::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACeilingTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

