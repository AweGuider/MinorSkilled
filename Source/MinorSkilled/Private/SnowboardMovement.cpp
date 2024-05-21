// Fill out your copyright notice in the Description page of Project Settings.


#include "SnowboardMovement.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
USnowboardMovement::USnowboardMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USnowboardMovement::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USnowboardMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

float USnowboardMovement::GetTest()
{
	return test;
}

void USnowboardMovement::SetTest(float NewValue)
{
	test = NewValue;
}

FVector USnowboardMovement::CalculateVelocity(FVector CurrentVelocity, FVector SnowboardForwardVector)
{
	GravityForce = FVector(0.0f, 0.0f, -1.0f) * GravityConstant * GravityForceMultiplier;
	UE_LOG(LogTemp, Warning, TEXT("Gravity: %s"), *GravityForce.ToString());

	FVector NormalizedSnowboardNormalCross = SnowboardForwardVector.Cross(OutHitNormal).GetSafeNormal();
	
	float SnowboardNormalDot = NormalizedSnowboardNormalCross.Dot(CurrentVelocity);

	FrictionForce = -FrictionCoefficient * (NormalizedSnowboardNormalCross * SnowboardNormalDot);
	UE_LOG(LogTemp, Warning, TEXT("Friction: %s"), *FrictionForce.ToString());
	NewVelocity = MoveSpeed * (GravityForce + FrictionForce) + CurrentVelocity;

	return NewVelocity;
}

FVector USnowboardMovement::ProcessLineTrace(bool bHit, FVector HitNormal)
{
	Grounded = bHit;

	if (Grounded)
	{
		OutHitNormal = HitNormal;
	}

	return OutHitNormal;
}

void USnowboardMovement::AlignSnowboardWithSlope(UStaticMeshComponent* Snowboard, float DeltaTime)
{
	// Assuming 'this' is an Actor or has access to an Actor
	AActor* MyActor = GetOwner();
	if (!MyActor) return;

	if (Grounded)
	{
		FVector SnowboardForwardVector = Snowboard->GetForwardVector();

		FRotator TargetRotation = UKismetMathLibrary::MakeRotFromZX(OutHitNormal, SnowboardForwardVector);
	
		// Get current actor rotation
		FRotator CurrentRotation = MyActor->GetActorRotation();

		FRotator NewRotation = UKismetMathLibrary::RInterpTo(CurrentRotation, TargetRotation, DeltaTime, SnowboardRotationInterpSpeed);

		MyActor->SetActorRotation(NewRotation);
	}
}

void USnowboardMovement::OnBlaBlaTestEvent_Implementation()
{

}

void USnowboardMovement::TestPrint()
{
}
