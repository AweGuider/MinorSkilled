// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HighScoreManager.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class MINORSKILLED_API UHighScoreManager : public UObject
{
	GENERATED_BODY()

private:

public:
    UHighScoreManager();

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Scores")
    int32 HighScore;

    void Initialize();  // Function to initialize or load high score

    // Setter to set high score
    UFUNCTION(BlueprintCallable, Category = "Scores")
    void SetHighScore(int32 NewScore);  // Function to update high score

    // Updates high score
    UFUNCTION(BlueprintCallable, Category = "Scores")
    void UpdateHighScore(int32 ScoreChange);  // Function to update high score

    // Getter for HighScore
    UFUNCTION(BlueprintPure, Category = "Scores")  // Adding UFUNCTION to expose to Blueprints
    int32 GetHighScore() const // Function to get high score
    {
        return HighScore;
    };
};
