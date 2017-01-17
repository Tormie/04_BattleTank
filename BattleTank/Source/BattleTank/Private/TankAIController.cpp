// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	if (!ATankAIController::GetControlledTank())
	{
		UE_LOG(LogTemp, Error, TEXT("AIController has no controlled Tank!"));
	}
	else
	{
		auto PlayerTank = ATankAIController::GetPlayerTank();
		if (!PlayerTank)
		{
			UE_LOG(LogTemp, Error, TEXT("No Player Tank found!"));
		}
		else
		{
			FString TankName = PlayerTank->GetName();
			UE_LOG(LogTemp, Warning, TEXT("AIController targeted: %s!"), *TankName);
		}
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}