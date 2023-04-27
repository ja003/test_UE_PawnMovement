// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GameFramework/Actor.h"
#include "MyAiController.generated.h"

UCLASS()
class TOPDOWN_API AMyAiController : public AAIController
{
	GENERATED_BODY()

public:
	
	AMyAiController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};
