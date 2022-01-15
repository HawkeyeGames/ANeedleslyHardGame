// Fill out your copyright notice in the Description page of Project Settings.


#include "ANeedleslyHardGame/Actors/DisasterPlate.h"
#include "ANeedleslyHardGame/ANeedleslyHardGameCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADisasterPlate::ADisasterPlate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("The root component"));
	RootComponent = Root;

	Plate = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("The mesh for the plate"));
	Plate->SetupAttachment(Root);
	Plate->OnComponentHit.AddDynamic(this, &ADisasterPlate::TouchedPlate);
}

// Called when the game starts or when spawned
void ADisasterPlate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADisasterPlate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADisasterPlate::TouchedPlate(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	APawn* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	AANeedleslyHardGameCharacter* Player = Cast<AANeedleslyHardGameCharacter>(PlayerCharacter);

	if (!bCanTrigger) return;
	if (PlayerCharacter == nullptr) return;
	if (Player == nullptr) return;

	if (bTriggered) return;

	if (OtherActor == Player)
	{
		UE_LOG(LogTemp, Warning, TEXT("You hit %s!"), *FString(GetName()));
		TriggerDisaster();
	}
}