// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class UE5MONDAYPROJECT_API AMenuHUD : public AHUD
{
	GENERATED_BODY()

protected:
	TSharedPtr<class SMainMenuWidget> MenuWidget;
	TSharedPtr<class SInGameWidget> GameWidget;
	TSharedPtr<class SWidget> MenuWidgetContainer;

	virtual void BeginPlay() override;

public:

	int points = 0;

	void ShowGame();
	void ShowMenu();
	void HideMenu();
	void AddPoints();

};
