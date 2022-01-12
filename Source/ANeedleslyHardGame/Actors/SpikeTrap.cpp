// Fill out your copyright notice in the Description page of Project Settings.


#include "ANeedleslyHardGame/Actors/SpikeTrap.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "ANeedleslyHardGame/ANeedleslyHardGameCharacter.h"
#include "Components/SkeletalMeshComponent.h"

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

	GetWorldTimerManager().SetTimer(Timer, this, &ASpikeTrap::DeathTimerDone, 1.f, true, 2.f);

	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetIgnoreMoveInput(true);

	Player = Cast<AANeedleslyHardGameCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	Player->GetMesh()->SetVisibility(false);
	Player->DeathParticle->SetActive(true);

	GetWorldTimerManager().SetTimer(ParticleTimer, this, &ASpikeTrap::ParticleTimerDone, 1.f, true, 0.2f);

	Player->bCanJump = false;
}

void ASpikeTrap::DeathTimerDone()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName(UGameplayStatics::GetCurrentLevelName(GetWorld())));
}

void ASpikeTrap::ParticleTimerDone()
{
	Player->DeathParticle->SetActive(false);
}
