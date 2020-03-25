// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"

// Sets default values
AFloater::AFloater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	SetRootComponent(StaticMesh);

	InitialLocation = FVector(0.f);
	PlacedLocation = FVector(0.f);
	WorldOrigin = FVector(0.f, 0.f, 0.f);
	InitialDirection = FVector(0.f, 0.f, 0.f);

	bInitializeFloaterLocations = false;
	bShouldFloat = false;

	RunningTime = 0.f;
}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();

	PlacedLocation = GetActorLocation();
	
	if (bInitializeFloaterLocations)
	{
		SetActorLocation(InitialLocation);
	}
}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bShouldFloat)
	{
		FVector NewLocation = GetActorLocation();

		NewLocation.Z = NewLocation.Z + (.5f) * FMath::Sin((30.f) * RunningTime); // if you multiply the sin function you change the amplitude (how high/low it bobs); multiplying the RunningTime relates to the speed of the oscillations


		SetActorLocation(NewLocation);
		RunningTime += DeltaTime;
		UE_LOG(LogTemp, Warning, TEXT("Running time: %f"), RunningTime);
	}
}

