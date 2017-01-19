// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CannonProjectile.generated.h"

UCLASS()
class BATTLETANK_API ACannonProjectile : public AActor
{
	GENERATED_BODY()
	
private:
	UProjectileMovementComponent* ProjectileMovement = nullptr;

public:	
	// Sets default values for this actor's properties
	ACannonProjectile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void LaunchProjectile(float Speed);
	
};
