// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPathFollowingComponent.h"

#include "AIController.h"
#include "MyPawn.h"

FAIRequestID UMyPathFollowingComponent::RequestMove(const FAIMoveRequest& RequestData, FNavPathSharedPtr InPath)
{
	FVector DebugPoint = Cast<AMyPawn>(Cast<AAIController>(GetOwner())->GetPawn())->DebugPoint;
	
	InPath->GetPathPoints().Add(FNavPathPoint(DebugPoint));
	
	return Super::RequestMove(RequestData, InPath);
}

void UMyPathFollowingComponent::SetMoveSegment(int32 SegmentStartIndex)
{
	Super::SetMoveSegment(SegmentStartIndex);

	//CurrentDestination.Position += FVector::ForwardVector * 500;
	//UE_LOG(LogTemp, Log, TEXT("xxx MoveSegmentDirection = %s"), *MoveSegmentDirection.ToString());
	//MoveSegmentDirection = FVector::ForwardVector;

	DrawDebugSphere(GWorld, CurrentDestination.Position, 30, 10, FColor::Blue, true, 100);
}

bool UMyPathFollowingComponent::HasReachedCurrentTarget(const FVector& CurrentLocation) const
{
	return Super::HasReachedCurrentTarget(CurrentLocation);

	if (MovementComp == NULL)
	{
		return false;
	}

	const FVector CurrentTarget = GetCurrentTargetLocation();
	const FVector CurrentDirection = GetCurrentDirection();

	// check if moved too far
	const FVector ToTarget = (CurrentTarget - MovementComp->GetActorFeetLocation());

	FVector lineStart = Cast<AAIController>(GetOwner())->GetPawn()->GetActorLocation();
	
	//UE_LOG(LogTemp, Log, TEXT("xxx lineStart = %s"), *lineStart.ToString());
	//DrawDebugLine(GetWorld(), lineStart, lineStart + CurrentDirection * 300, FColor::Purple, true, 5);

	const float SegmentDot = FVector::DotProduct(ToTarget, CurrentDirection);
	if (SegmentDot < 0.0)
	{
		return true;
	}

	// or standing at target position
	// don't use acceptance radius here, it has to be exact for moving near corners (2D test < 5% of agent radius)
	const float GoalRadius = 0.0f;
	const float GoalHalfHeight = 0.0f;

	return HasReachedInternal(CurrentTarget, GoalRadius, GoalHalfHeight, CurrentLocation, CurrentAcceptanceRadius, 0.05f);
}
