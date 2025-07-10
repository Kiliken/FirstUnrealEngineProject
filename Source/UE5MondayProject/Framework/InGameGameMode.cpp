// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameGameMode.h"
#include "../Character/BallPlayer.h"
//#include "Blueprint/UserWidget.h"





AInGameGameMode::AInGameGameMode()
{
	DefaultPawnClass = ABallPlayer::StaticClass();
}

void AInGameGameMode::BeginPlay() {
	Super::BeginPlay();

	

#if 0
    FSoftClassPath blackLinesWidgeClasstRef(TEXT("WidgetBlueprint'/Game/UI/BasicUI.BasicUI_C'"));
    UClass* blackLinesWidgetClass = blackLinesWidgeClasstRef.TryLoadClass<UUserWidget>();
    if (blackLinesWidgetClass)
    {
        UUserWidget* blackLinesWidget = CreateWidget<UUserWidget>(this->GetGameInstance(), blackLinesWidgetClass);
        if (blackLinesWidget)
            blackLinesWidget->AddToViewport();
    }
#endif

}


