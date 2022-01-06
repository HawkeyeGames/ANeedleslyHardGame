// Fill out your copyright notice in the Description page of Project Settings.


#include "ANeedleslyHardGame/Actors/SpikeTrap.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ASpikeTrap::ASpikeTrap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root component");
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Spikes mesh");
	Mesh->SetupAttachment(RootComponent);

	Trigger = CreateDefaultSubobject<UBoxComponent>("Box trigger component");
	Trigger->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASpikeTrap::BeginPlay()
{
	Super::BeginPlay();
	
	StartLoc = Mesh->GetComponentLocation();
}

// Called every frame
void ASpikeTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpikeTrap::OnTriggered()
{
	FLatentActionInfo LatentInfo;
	bCanTrigger = false;
	
	UKismetSystemLibrary::MoveComponentTo(Mesh, FVector(0.f,0.f,0.f), Mesh->GetComponentRotation(), true, true, 0.2f, false, EMoveComponentAction::Move, LatentInfo);

	GetWorld()->GetTimerManager().SetTimer(Timer, this, &ASpikeTrap::TimerEnd, 3.f, false);

	UE_LOG(LogTemp, Warning, TEXT("Triggered spike trap."));
}

void ASpikeTrap::TimerEnd()
{
	FLatentActionInfo LatentInfo;
	bCanTrigger = true;

	UKismetSystemLibrary::MoveComponentTo(Mesh, FVector(0.f, 0.f, 0.f), Mesh->GetComponentRotation(), true, true, 0.2f, false, EMoveComponentAction::Move, LatentInfo);
}



