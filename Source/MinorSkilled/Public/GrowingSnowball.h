// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GrowingSnowball.generated.h"

UCLASS()
class MINORSKILLED_API AGrowingSnowball : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom", meta = (AllowPrivateAccess = "true"))
	float CurrentSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom", meta = (AllowPrivateAccess = "true"))
	float MaxSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom", meta = (AllowPrivateAccess = "true"))
	float GrowAmount;

	// Initialize your boolean variable, visible and editable in Blueprints
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gameplay", meta = (AllowPrivateAccess = "true"))
	bool bIsActivated;
	
public:	
	// Sets default values for this actor's properties
	AGrowingSnowball();

	
	UFUNCTION(BlueprintCallable , BlueprintImplementableEvent, Category = "Gameplay")
	void Activate(
		bool Activate
	);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

};
