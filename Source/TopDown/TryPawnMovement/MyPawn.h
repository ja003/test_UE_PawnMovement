// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPawnMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UCLASS()
class TOPDOWN_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	AMyPawn();

protected:
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UMyPawnMovementComponent> MyPawnMovementComponent;
};
