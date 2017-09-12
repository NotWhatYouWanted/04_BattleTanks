// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController_CPP.h"
#include "GameFramework/Controller.h"

void ATankPlayerController_CPP::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play!"));

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) { UE_LOG(LogTemp, Warning, TEXT("Player Controller not possessing a tank")); }
	else { UE_LOG(LogTemp, Warning, TEXT("Player posessing %s."), *(ControlledTank->GetName())); }
}

void ATankPlayerController_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("Player Controller ticking"));
	AimTowardsCrosshair();
}

ATank* ATankPlayerController_CPP::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController_CPP::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; //Out parameter
	if (bGetSightRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());
		//TODO Tell controlled tank to aim at hit point
	}
	return;
}

bool ATankPlayerController_CPP::bGetSightRayHitLocation(FVector& OutHitLocation) const
{
	//Find crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	auto ScreenLocation 
		= FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("Crosshair location on screen: %s"), *ScreenLocation.ToString());

	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{ UE_LOG(LogTemp, Warning, TEXT("Look direction is: %s"), *LookDirection.ToString()); }
	//Linetrace through crosshair
	//Check if anything is hit (in max range)
		//If hit, update hitlocation, return true
	//Else,
	return true;
}

bool ATankPlayerController_CPP::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; //To be discarded
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}
