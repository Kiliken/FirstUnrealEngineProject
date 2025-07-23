// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuHUD.h"
#include "SSMainMenuWidget.h"
#include "SInGameWidget.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"

void AMenuHUD::BeginPlay(){
	Super::BeginPlay();

	

	ShowGame();
}

void AMenuHUD::ShowMenu() {

	if (GEngine && GEngine->GameViewport) {
		MenuWidget = SNew(SMainMenuWidget).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuWidgetContainer, SWeakWidget).PossiblyNullContent(MenuWidget.ToSharedRef()));
	
		if (PlayerOwner) {
			PlayerOwner->bShowMouseCursor = true;
			PlayerOwner->SetInputMode(FInputModeUIOnly());
		}
	}
}

void AMenuHUD::HideMenu() {
	
	if (GEngine && GEngine->GameViewport && MenuWidget.IsValid() && MenuWidgetContainer.IsValid()) {
		GEngine->GameViewport->RemoveViewportWidgetContent(MenuWidgetContainer.ToSharedRef());

		if (PlayerOwner) {
			PlayerOwner->bShowMouseCursor = false;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}
}

void AMenuHUD::ShowGame() {

	if (GEngine && GEngine->GameViewport) {
		GameWidget = SNew(SInGameWidget).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuWidgetContainer, SWeakWidget).PossiblyNullContent(GameWidget.ToSharedRef()));
		
		if (PlayerOwner) {
			PlayerOwner->bShowMouseCursor = false;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}
}

void AMenuHUD::AddPoints() {
	points += 1;


	if (GEngine && GEngine->GameViewport) {
		GameWidget = SNew(SInGameWidget).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuWidgetContainer, SWeakWidget).PossiblyNullContent(GameWidget.ToSharedRef()));


		if (PlayerOwner) {
			PlayerOwner->bShowMouseCursor = false;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}
}

