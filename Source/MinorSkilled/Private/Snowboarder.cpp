// Fill out your copyright notice in the Description page of Project Settings.


#include "Snowboarder.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"

// Sets default values
ASnowboarder::ASnowboarder()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GravityConstant = 9.81f;
}

// Called when the game starts or when spawned
void ASnowboarder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASnowboarder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASnowboarder::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ASnowboarder::CalculateVelocity(FVector CurrentVelocity)
{
	DrawDebugArrowInDirection(SnowboardForwardVector.GetSafeNormal(), SnowboardForwardColor, DebugSnowboardForward);

	GravityForce = FVector(0.0f, 0.0f, -1.0f) * GravityConstant * GravityForceMultiplier;
	
	DrawDebugArrowInDirection(GravityForce.GetSafeNormal(), GravityForceColor, DebugGravityForce);

	//UE_LOG(LogTemp, Warning, TEXT("Gravity: %s"), *GravityForce.ToString());

	FVector SnowboardNormalCross = SnowboardForwardVector.Cross(OutHitNormal);
	FVector NormalizedSnowboardNormalCross = SnowboardNormalCross.GetSafeNormal();

	DrawDebugArrowInDirection(NormalizedSnowboardNormalCross, SidewaysVectorColor, DebugSideways);

	float SnowboardNormalDot = NormalizedSnowboardNormalCross.Dot(CurrentVelocity);

	FrictionForce = -FrictionCoefficient * (NormalizedSnowboardNormalCross * SnowboardNormalDot);

	DrawDebugArrowInDirection(FrictionForce, FrictionForceColor, DebugFriction);

	//UE_LOG(LogTemp, Warning, TEXT("Friction: %s"), *FrictionForce.ToString());
	NewVelocity = MoveSpeed * (GravityForce + FrictionForce) + CurrentVelocity;

	DrawDebugArrowInDirection(NewVelocity.GetSafeNormal(), VelocityColor, DebugVelocity);
}

void ASnowboarder::ProcessLineTrace(bool bHit, FVector HitNormal)
{
	Grounded = bHit;

	if (Grounded)
	{
		OutHitNormal = HitNormal;
	}

	DrawDebugArrowInDirection(OutHitNormal.GetSafeNormal(), SlopeNormalColor, DebugSlopeNormal);
}

// #TODO Aligning does not work
void ASnowboarder::AlignSnowboardWithSlope(float DeltaTime)
{
	// Assuming 'this' is an Actor or has access to an Actor
	AActor* MyActor = GetOwner();
	if (!MyActor) return;

	if (Grounded)
	{
		// #TODO Need to learn how to debug and check if code gets here
		FRotator TargetRotation = UKismetMathLibrary::MakeRotFromZX(OutHitNormal, SnowboardForwardVector);

		// Get current actor rotation
		FRotator CurrentRotation = MyActor->GetActorRotation();

		FRotator NewRotation = UKismetMathLibrary::RInterpTo(CurrentRotation, TargetRotation, DeltaTime, SnowboardRotationInterpSpeed);

		MyActor->SetActorRotation(NewRotation);
	}
}

