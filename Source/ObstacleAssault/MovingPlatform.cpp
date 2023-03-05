// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartingLocation = GetActorLocation();
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	FVector CurrentLocation = GetActorLocation();

	CurrentLocation += PlatformVelocity * DeltaTime;

	SetActorLocation(CurrentLocation);

	double DistanceTravelled = FVector::Dist(StartingLocation, CurrentLocation);

	if (DistanceTravelled > MoveDistance) {
		FVector PlatformDirection = PlatformVelocity.GetSafeNormal();
		StartingLocation = StartingLocation + PlatformDirection * MoveDistance;
		SetActorLocation(StartingLocation);
		PlatformVelocity = -PlatformVelocity;
	}


}
 