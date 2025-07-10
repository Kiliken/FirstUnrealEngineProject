// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include "Kismet/KismetSystemLibrary.h" 
#include "Kismet/GameplayStatics.h" 




// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();

	//_pA = new AEnemyActor[20];
	//UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("SCORE: %d"), _score), true, false, FColor::Cyan);
	
	for (int i = 0; i < 20; i++) {
		_pA[i] = GetWorld()->SpawnActor<AEnemyActor>(); 
		_pA[i]->SetActorLocation(SPAWN_POS);
	}
	
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
#if 1

	_timer += DeltaTime;

	if (_timer <= 60.f) {
		for (int i = 0; i < 20; i++) {
			if (_pA[i]->_isAlive != true) {
				_pA[i]->_isAlive = true;
				_score++;
				//UKismetSystemLibrary::FlushDebugStrings(this);
				//UKismetSystemLibrary::DrawDebugString(this, _pA[i]->GetActorLocation(), TEXT("+1"), NULL, FColor::Red, 1);
				//UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("SCORE: %d"), _score), true, false, FColor::Cyan);

				_pA[i] = GetWorld()->SpawnActor<AEnemyActor>(); 
				_pA[i]->SetActorLocation(SPAWN_POS);
			}
		}
	}
	else{
		UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("GAME CLEAR! FINAL SCORE: %d!"), _score), true, false, FColor::Cyan);

		if (_timer >= 63.f && _inGame) {
			//FString aTChar = FString::Printf(TEXT("echo %%date%%/%%time%%) FINAL SCORE : %d >> %%USERPROFILE%%/Desktop/MarianiGameScore.txt"), _score);
			//system(TCHAR_TO_ANSI(*aTChar));
			FGenericPlatformMisc::RequestExit(false);
			_inGame = false;
		}
			

	}


	

	

#endif
}

