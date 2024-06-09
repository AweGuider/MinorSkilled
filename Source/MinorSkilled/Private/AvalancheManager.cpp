// Fill out your copyright notice in the Description page of Project Settings.


#include "AvalancheManager.h"

// Sets default values
AAvalancheManager::AAvalancheManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AAvalancheManager::TriggerAvalanche()
{
    // Logic to release snowballs or start particle effects
    for (AGrowingSnowball* Snowball : Snowballs)
    {
        if (Snowball)
        {
            Snowball->Activate(true);
        }
    }
}

