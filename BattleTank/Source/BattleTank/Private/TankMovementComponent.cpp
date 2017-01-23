// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}


void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (Throw != 0.f)
	{
		UE_LOG(LogTemp, Warning, TEXT("Intend move forward Throw: %f"), Throw);
		LeftTrack->SetThrottle(Throw);
		RightTrack->SetThrottle(Throw);
	}
}