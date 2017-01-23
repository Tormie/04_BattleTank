// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTracks.h"


// Sets default values
ATankTracks::ATankTracks()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATankTracks::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATankTracks::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

