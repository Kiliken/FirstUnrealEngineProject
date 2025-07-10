// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "InGameGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UE5MONDAYPROJECT_API AInGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

	

public:
	// Constructor
	AInGameGameMode();


protected:




};
