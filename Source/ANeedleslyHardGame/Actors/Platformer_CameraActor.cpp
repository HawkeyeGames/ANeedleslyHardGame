// Fill out your copyright notice in the Description page of Project Settings.


#include "ANeedleslyHardGame/Actors/Platformer_CameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "ANeedleslyHardGame/ANeedleslyHardGameCharacter.h"

// Sets default values
APlatformer_CameraActor::APlatformer_CameraActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	Camera->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APlatformer_CameraActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlatformer_CameraActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (SectionEnd == nullptr) return;
	
	FVector NewLoc;

	APawn* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	AANeedleslyHardGameCharacter* Player = Cast<AANeedleslyHardGameCharacter>(PlayerCharacter);


	if (Player == nullptr) return;
	AvgLoc = (SectionEnd->GetActorLocation() + Player->GetActorLocation()) / 2;

	if (Player->bDead) return;
	
	if (bTransitioning) return;

	NewLoc.X = AvgLoc.X + Offset;
	NewLoc.Y = AvgLoc.Y;
	NewLoc.Z = AvgLoc.Z;

	SetActorLocation(NewLoc);
	
}

