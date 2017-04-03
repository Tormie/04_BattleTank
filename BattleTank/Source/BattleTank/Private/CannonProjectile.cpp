// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "CannonProjectile.h"


// Sets default values
ACannonProjectile::ACannonProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Movement Component"));
	ProjectileMovement->bAutoActivate = false;

	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
	SetRootComponent(CollisionMesh);
	CollisionMesh->SetNotifyRigidBodyCollision(true);
	CollisionMesh->SetVisibility(false);

	LaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Launch Blast"));
	LaunchBlast->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void ACannonProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACannonProjectile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ACannonProjectile::LaunchProjectile(float Speed)
{
	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	ProjectileMovement->Activate();
}