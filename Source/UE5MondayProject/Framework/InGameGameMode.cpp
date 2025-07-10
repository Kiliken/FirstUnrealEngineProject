// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameGameMode.h"
#include "../Character/BallPlayer.h"
#include "../MenuHUD.h"
//#include "Blueprint/UserWidget.h"





AInGameGameMode::AInGameGameMode()
{
	DefaultPawnClass = ABallPlayer::StaticClass();
	HUDClass = AMenuHUD::StaticClass();
}

void AInGameGameMode::BeginPlay() {
	Super::BeginPlay();


}


