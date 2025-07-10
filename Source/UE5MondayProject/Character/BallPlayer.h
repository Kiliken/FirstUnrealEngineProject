#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputMappingContext.h" 
#include "InputAction.h" 
#include "InputActionValue.h" 
#include "BallPlayer.generated.h"
class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class UE5MONDAYPROJECT_API ABallPlayer : public APawn
{
	GENERATED_BODY()


public:
	
	ABallPlayer();

protected:
	
	virtual void BeginPlay() override;

	
	UPROPERTY(EditAnywhere, Category = Input)
	class UInputMappingContext* DefaultMappingContext;

	
	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* ActionInput;

	
	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* AxisInput;

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* CameraAxisInput;

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* SprintInput;

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* PauseInput;

public:
	
	virtual void Tick(float DeltaTime) override;

	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	
	UPROPERTY(VisibleAnywhere, Category = Character, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Sphere;

	
	UPROPERTY(VisibleAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> SpringArm;

	
	UPROPERTY(VisibleAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> Camera;

	void SetupInput();

	
	void PressedAction();
	void ReleasedAction();

	void SprintIn();
	void SprintOut();

	void PauseGame();

	
	void PressedAxis(const FInputActionValue& Value);
	void CameraAxisMovement(const FInputActionValue& Value);

	
	bool IsPressed = false;

	float velocity = 5.f;

public:
	UPROPERTY(EditAnywhere, Category = "PlayerVar")
	AActor* _player;
};
