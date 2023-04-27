// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAiController.h"

#include "MyPathFollowingComponent.h"



AMyAiController::AMyAiController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<UMyPathFollowingComponent>(TEXT("PathFollowingComponent")))
{
}
