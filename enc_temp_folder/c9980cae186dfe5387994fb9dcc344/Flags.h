// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Materials/MaterialInterface.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Flags.generated.h"

UCLASS()
class MINORSKILLED_API AFlags : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlags();

	UPROPERTY(EditAnywhere, Category = "Materials")
	UMaterialInterface* GreenMaterial; // Material to set when flags are triggered
	
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* LeftFlagMesh;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* RightFlagMesh;

	UPROPERTY(EditAnywhere, Category = "Components")
	UBoxComponent* TriggerVolume;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



	UFUNCTION()
	void OnPlayerPassThrough(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
