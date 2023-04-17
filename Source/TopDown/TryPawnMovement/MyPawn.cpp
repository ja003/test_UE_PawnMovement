// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"

#include "MyPawnMovementComponent.h"


// Sets default values
AMyPawn::AMyPawn()
{
	MyPawnMovementComponent = CreateDefaultSubobject<UMyPawnMovementComponent>(TEXT("MyPawnMovementComponent"));
}

