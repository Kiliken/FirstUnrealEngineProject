// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../MyRand.h"
#include "time.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyActor.generated.h"


UCLASS()
class UE5MONDAYPROJECT_API AEnemyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	UPROPERTY(VisibleAnywhere, Category = Character, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> m_Sphere;

	bool _isAlive = true;

private:
	FVector _randomPos;

	MyRand _randNum;
	AActor* _player;
};
