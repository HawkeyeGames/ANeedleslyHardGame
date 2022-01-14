// Fill out your copyright notice in the Description page of Project Settings.


#include "ANeedleslyHardGame/Actors/TurretTrap.h"
#include "ANeedleslyHardGame/ANeedleslyHardGameCharacter.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ATurretTrap::ATurretTrap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("The root component"));
	RootComponent = Root;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("The trigger box"));
	TriggerBox->SetupAttachment(Root);

	Neck = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("The mesh for the neck"));
	Neck->SetupAttachment(Root);

	Gun = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("The mesh for the gun"));
	Gun->SetupAttachment(Neck);
}

// Called when the game starts or when spawned
void ATurretTrap::BeginPlay()
{
	Super::BeginPlay();

	int32 TriggerChance = FMath::RandRange(1, TriggerChanceMax);

	if (TriggerChance == 1)
	{
		bCanTrigger = true;
	}
}

// Called every frame
void ATurretTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bTriggered)
	{
		FVector PlayerLoc = UGameplayStatics::GetPlayerPawn(GetWorld(), 0)->GetActorLocation();
		FRotator GunRot = UKismetMathLibrary::FindLookAtRotation(Gun->GetComponentLocation(), PlayerLoc);

		Gun->SetWorldRotation(GunRot);
	}

}

void ATurretTrap::Shoot()
{
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	AANeedleslyHardGameCharacter* Player = Cast<AANeedleslyHardGameCharacter>(PlayerPawn);

	Player->bDead = true;
	Player->GetController()->SetIgnoreMoveInput(true);
	Player->bCanJump = false;
	Player->GetMesh()->SetVisibility(false);
}

