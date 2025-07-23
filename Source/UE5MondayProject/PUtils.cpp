// LIKE IN UNITY

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PUtils.h"
#include <Kismet/GameplayStatics.h>
#include <Engine/World.h>

namespace PUTILS{

static AActor* GetActorByName(FString actorName, UWorld* world) {

	TArray<AActor*> actorInScene{};

	UGameplayStatics::GetAllActorsOfClass(world, AActor::StaticClass(), actorInScene);

	for (AActor* actor : actorInScene) {
		if (actor == nullptr) return nullptr;

		if (actor->GetActorLabel() == actorName) return actor;
	}

	return nullptr;
}

}

