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

ATank* ATankPlayerController_CPP::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


