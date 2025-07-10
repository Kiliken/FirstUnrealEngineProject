// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyActor.h"
#include "BallPlayer.h"
#include "Kismet/GameplayStatics.h"



// Sets default values
AEnemyActor::AEnemyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Sphere"));

	// StaticMesh��StaticMeshComponent�ɐݒ肷��
	m_Sphere->SetStaticMesh(Mesh);

	// Material��StaticMesh�ɐݒ肷��
	UMaterial* Material = LoadObject<UMaterial>(nullptr, TEXT("/Engine/BasicShapes/BasicShapeMaterial"));

	// Material��StaticMeshComponent�ɐݒ肷��
	m_Sphere->SetMaterial(0, Material);
	m_Sphere->SetStaticMesh(Mesh);
	m_Sphere->SetupAttachment(RootComponent);

	m_Sphere->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	
}

// Called when the game starts or when spawned
void AEnemyActor::BeginPlay()
{
	Super::BeginPlay();
	_player = UGameplayStatics::GetActorOfClass(GetWorld(), ABallPlayer::StaticClass());

	_randNum.initSeed(time(NULL) + rand());
	
}

// Called every frame
void AEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	FVector pos = this->GetActorLocation();
	FVector playerPos = _player->GetActorLocation();
	
	if (FVector::Distance(_randomPos,pos) <= 100.f || _randomPos.IsZero() ) {
		
		//UE_LOG(LogTemp, Warning, TEXT("Rand: %d"), randNum.rand());
		_randomPos.Y = (float)_randNum.rand();
		_randomPos.X = (float)_randNum.rand();
		_randomPos.Z = 50.f;
		
	}
	else {
		FVector dir = _randomPos - pos;
		dir = dir.GetSafeNormal();
		pos += dir * 1200.f * DeltaTime;
		this->SetActorLocation(pos);
	}
	
	if (FVector::Distance(pos, playerPos) <= 100.f) {
		this->K2_DestroyActor();
		_isAlive = false;
	}
}

