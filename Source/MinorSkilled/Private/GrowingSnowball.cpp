// Fill out your copyright notice in the Description page of Project Settings.


#include "GrowingSnowball.h"

// Sets default values
AGrowingSnowball::AGrowingSnowball()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGrowingSnowball::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGrowingSnowball::Tick(float DeltaTime)
{
    // Increase size over time
    CurrentSize += DeltaTime;
    SetActorScale3D(FVector(CurrentSize));
}

