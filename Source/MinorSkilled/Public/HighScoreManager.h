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



public:

    UFUNCTION(BlueprintCallable, Category = "High Score")
    static UHighScoreManager* GetInstance();  // Function to get instance of HighScoreManager

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "High Score")
    int32 HighScore;

    void Initialize();  // Function to initialize or load high score

    // Setter to set high score
    UFUNCTION(BlueprintCallable, Category = "High Score")
    void RandomHighScore();  // Function to set random high score

    // Setter to set high score
    UFUNCTION(BlueprintCallable, Category = "High Score")
    void ResetHighScore();  // Function to update high score

    // Setter to set high score
    UFUNCTION(BlueprintCallable, Category = "High Score")
    void SetHighScore(int32 NewScore);  // Function to update high score

    // Updates high score
    UFUNCTION(BlueprintCallable, Category = "High Score")
    void UpdateHighScore(int32 ScoreChange);  // Function to update high score

    // Getter for HighScore
    UFUNCTION(BlueprintPure, Category = "High Score")  // Adding UFUNCTION to expose to Blueprints
    int32 GetHighScore() const // Function to get high score
    {
        return HighScore;
    };

private:

    static UHighScoreManager* Instance;  // Static instance of HighScoreManager

    UHighScoreManager();

};

UHighScoreManager* UHighScoreManager::Instance = nullptr; // Initialize static instance to nullptr
