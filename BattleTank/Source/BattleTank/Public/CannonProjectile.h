// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CannonProjectile.generated.h"

UCLASS()
class BATTLETANK_API ACannonProjectile : public AActor
{
	GENERATED_BODY()
	
private:

	void OnTimerExpire();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float DestroyDelay = 10.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float ProjectileDamage = 20.f;

	UPROPERTY(VisibleAnywhere, Category = "ProjectileComponent")
	UProjectileMovementComponent* ProjectileMovement = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "ProjectileComponent")
	UStaticMeshComponent* CollisionMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "ProjectileComponent")
	UParticleSystemComponent* LaunchBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "ProjectileComponent")
	UParticleSystemComponent* ImpactBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "ProjectileComponent")
	URadialForceComponent* ExplosionForce = nullptr;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

public:	
	// Sets default values for this actor's properties
	ACannonProjectile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void LaunchProjectile(float Speed);

};
