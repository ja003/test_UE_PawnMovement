// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Navigation/PathFollowingComponent.h"
#include "MyPathFollowingComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TOPDOWN_API UMyPathFollowingComponent : public UPathFollowingComponent
{
	GENERATED_BODY()

	virtual FAIRequestID RequestMove(const FAIMoveRequest& RequestData, FNavPathSharedPtr InPath) override;
	
	virtual void SetMoveSegment(int32 SegmentStartIndex) override;

	virtual bool HasReachedCurrentTarget(const FVector& CurrentLocation) const override;


	
};
