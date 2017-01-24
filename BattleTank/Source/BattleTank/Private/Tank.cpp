// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "CannonProjectile.h"
#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"


void ATank::BeginPlay()
{
	Super::BeginPlay();
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s TORMIE: Tank C++ Begin Play"), *TankName);
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s TORMIE: Tank C++ Construct"), *TankName);

	//TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
}

void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (Barrel && isReloaded)
	{
		// Spawn a projectile at the socket location on the barrel.
		auto Projectile = GetWorld()->SpawnActor<ACannonProjectile>(
			CannonProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();

	}
	else {
		UE_LOG(LogTemp, Error, TEXT("NO BARREL DETECTED!"));
	}
}

void ATank::AimAt(FVector HitLocation)
{
	if (!TankAimingComponent) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}