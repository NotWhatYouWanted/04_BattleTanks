// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (PlayerTank)
	{ 
		//Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius); //TODO Check radius is in CM
		//Aim towards player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		//Fire if ready
		ControlledTank->Fire();
	}

}
