// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	// No need to call Super as we're replacing functionality
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention);
	IntendMoveForward(ForwardThrow);
	IntendTurnRight(RightThrow.Z);
	UE_LOG(LogTemp, Warning, TEXT("Intended Right Turn: %f"), RightThrow.Z);
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	// TODO prevent higher speed due to double control input
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) {
		UE_LOG(LogTemp, Error, TEXT("Tank Tracks Issue"));
		return; 
	}
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
	// TODO prevent higher speed due to double control input
}