// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameFramework/ProjectileMovementComponent.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/PhysicsEngine/RadialForceComponent.h"
#include "Projectile.generated.h"

UCLASS()
class BATTLETANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

	void LaunchProjectile(float Speed);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UProjectileMovementComponent* MovementComponent = nullptr;

	UPROPERTY(VisibleAnywhere, Category = Components)
		UStaticMeshComponent* CollisionMesh = nullptr;

	UPROPERTY(EditAnywhere, Category = Components)
		UParticleSystemComponent* LaunchBlast = nullptr;

	UPROPERTY(EditAnywhere, Category = Components)
		UParticleSystemComponent* ImpactBlast = nullptr;

	UPROPERTY(EditAnywhere, Category = Components)
		URadialForceComponent* ExplosionForce = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = Components)
		float TimerDelay = 10.0f;

private:	

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void OnTimerExpire();
	
};
