// Fill out your copyright notice in the Description page of Project Settings.


#include "ANeedleslyHardGame/Actors/SpikeTrap.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

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
}

// Called every frame
void ASpikeTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpikeTrap::OnTriggered()
{
	FTimerHandle Timer;

	GetWorldTimerManager().SetTimer(Timer, this, &ASpikeTrap::TimerDone, 1.f, true, 2.f);
}

void ASpikeTrap::TimerDone()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName(UGameplayStatics::GetCurrentLevelName(GetWorld())));
}
