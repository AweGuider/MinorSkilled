// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SnowboardMovement.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MINORSKILLED_API USnowboardMovement : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USnowboardMovement();

	UFUNCTION(BlueprintCallable, Category = "Snowboard")
		FVector CalculateVelocity(FVector CurrentVelocity, FVector SnowboardForwardVector);

	UFUNCTION(BlueprintCallable, Category = "Utils")
		FVector ProcessLineTrace(bool bHit, FVector HitNormal);

	UFUNCTION(BlueprintCallable, Category = "Snowboard")
		void AlignSnowboardWithSlope(UStaticMeshComponent* Snowboard, float DeltaTime);


	// #TODO Need to be able to call custom DrawDebugArrow function in Blueprint from methods

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void DrawDebugArrowInDirections();

	UFUNCTION(BlueprintNativeEvent, Category = "Utils")
		void OnBlaBlaTestEvent();
		void OnBlaBlaTestEvent_Implementation();

	UFUNCTION(BlueprintCallable)
		void TestPrint();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		FVector OutHitNormal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		float Grounded;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		float SnowboardRotationInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		float LineTraceLength;


	// Gravity Force Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		float GravityConstant;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		float GravityForceMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		FVector GravityForce;

	// Friction Force Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		float FrictionCoefficient;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		FVector FrictionForce;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		float MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		FVector NewVelocity;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		float test;

	UFUNCTION(BlueprintPure, Category = "Custom")
		float GetTest();

	UFUNCTION(BlueprintCallable, Category = "Custom")
		void SetTest(float NewValue);
};
