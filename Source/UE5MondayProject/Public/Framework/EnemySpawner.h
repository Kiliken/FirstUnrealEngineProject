// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/EnemyActor.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"


UCLASS()
class UE5MONDAYPROJECT_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float const SPAWN_TIME = 3.f;
	FVector const SPAWN_POS = FVector(500, 500, 100);

	float _timer = 0;
	bool _inGame = true;
	int _score = 0;
	AEnemyActor *_pA[20];
	
};
