// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Snowboarder.generated.h"

UCLASS()
class MINORSKILLED_API ASnowboarder : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASnowboarder();

	UFUNCTION(BlueprintCallable, Category = "Snowboard")
		void CalculateVelocity(FVector CurrentVelocity);

	UFUNCTION(BlueprintCallable, Category = "Utils")
		void ProcessLineTrace(bool bHit, FVector HitNormal);

	UFUNCTION(BlueprintCallable, Category = "Snowboard")
		void AlignSnowboardWithSlope(float DeltaTime);

	UFUNCTION(BlueprintImplementableEvent)
		void DrawDebugArrowInDirection(
			FVector DirectionVector,
			FLinearColor ArrowColor,
			bool Enabled
		);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		bool FreeCameraEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		bool DisableSnowboard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		FVector SnowboardForwardVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		float TurningSpeed;

#pragma region Debug
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
		FVector DebugArrowsOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
		FLinearColor SidewaysInputColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
		bool DebugSlopeNormal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
		FLinearColor SlopeNormalColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
		bool DebugGravityForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
		FLinearColor GravityForceColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
		bool DebugSlopeProjection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
		FLinearColor SlopeProjectionColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
		bool DebugSnowboardForward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
		FLinearColor SnowboardForwardColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
		bool DebugSnowboardForwardProjection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
		FLinearColor SnowboardForwardProjectionColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
		bool DebugVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
		FLinearColor VelocityColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
		bool DebugSideways;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
		FLinearColor SidewaysVectorColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
		bool DebugFriction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
		FLinearColor FrictionForceColor;

#pragma endregion

	// Change to BlueprintReadOnly in later stages, keep for now for showcase
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		FVector OutHitNormal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		bool Grounded;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		float SnowboardRotationInterpSpeed;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		float GravityForceMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		float FrictionCoefficient;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		float MoveSpeed;

#pragma region Unused


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		bool PhysicsEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		bool CanMove;

#pragma endregion


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Custom")
		float GravityConstant;

	// Change to BlueprintReadOnly in later stages, keep for now for showcase
	UPROPERTY(BlueprintReadWrite, Transient, Category = "Physics")
		FVector GravityForce;

	// Change to BlueprintReadOnly in later stages, keep for now for showcase
	UPROPERTY(BlueprintReadWrite, Transient, Category = "Physics")
		FVector FrictionForce;

	// Change to BlueprintReadOnly in later stages, keep for now for showcase
	UPROPERTY(BlueprintReadWrite, Transient, Category = "Physics")
		FVector NewVelocity;

private:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom", meta = (AllowPrivateAccess = "true"))
		float LineTraceLength;
};

