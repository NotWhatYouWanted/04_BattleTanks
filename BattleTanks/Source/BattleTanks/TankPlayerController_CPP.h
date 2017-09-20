// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController_CPP.generated.h" //Must be last include!!

class ATank; //Forward declaration
 

UCLASS()
class BATTLETANKS_API ATankPlayerController_CPP : public APlayerController
{
	GENERATED_BODY()
	
private:
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;

	//Start the tank moving barrel to crosshair
	void AimTowardsCrosshair();

	//Returns OUT vector, true if hit landscape.
	bool bGetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector&HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000.0;

	UPROPERTY(EditDefaultsOnly)
		float CrosshairXLocation = 0.5;
	UPROPERTY(EditDefaultsOnly)
		float CrosshairYLocation = 0.333;

};
