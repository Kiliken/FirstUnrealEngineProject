
#include "BallPlayer.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetSystemLibrary.h" 
#include "Kismet/GameplayStatics.h" 
#include "Components/InputComponent.h" 
#include "EnhancedInputComponent.h" 
#include "EnhancedInputSubsystems.h" 



ABallPlayer::ABallPlayer()
{
	
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = Sphere;

	
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube"));

	
	Sphere->SetStaticMesh(Mesh);
	Sphere->BodyInstance.bLockYRotation = true;
	Sphere->BodyInstance.bLockXRotation = true;

	
	UMaterial* Material = LoadObject<UMaterial>(nullptr, TEXT("/Engine/BasicShapes/BasicShapeMaterial"));

	
	Sphere->SetMaterial(0, Material);

	
	Sphere->SetSimulatePhysics(true);
	
	

	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->SetupAttachment(RootComponent);

	
	SpringArm->SetRelativeRotation(FRotator(-30.0f, 0.0f, 0.0f));

	
	SpringArm->TargetArmLength = 450.0f;

	
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritRoll = false;

	
	SpringArm->bEnableCameraLag = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	Camera->SetupAttachment(SpringArm);

	ActionInput = LoadObject<UInputAction>(NULL, TEXT("/Game/Input/Actions/IA_Action"), NULL, LOAD_None, NULL);
	AxisInput = LoadObject<UInputAction>(NULL, TEXT("/Game/Input/Actions/IA_Axis"), NULL, LOAD_None, NULL);
	CameraAxisInput = LoadObject<UInputAction>(NULL, TEXT("/Game/Input/Actions/IA_CameraAxis"), NULL, LOAD_None, NULL);
	SprintInput = LoadObject<UInputAction>(NULL, TEXT("/Game/Input/Actions/IA_Sprint"), NULL, LOAD_None, NULL);

	
	DefaultMappingContext = LoadObject<UInputMappingContext>(NULL, TEXT("/Game/Input/IMC_Default"), NULL, LOAD_None, NULL);
}

// Called when the game starts or when spawned
void ABallPlayer::BeginPlay()
{
	Super::BeginPlay();

	SetupInput();

}

void ABallPlayer::SetupInput() {
	
	APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	EnableInput(controller);

	if (InputComponent)
	{
		// Set up action bindings
		if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent)) {

			// Input Action
			EnhancedInputComponent->BindAction(ActionInput, ETriggerEvent::Triggered, this, &ABallPlayer::PressedAction);
			EnhancedInputComponent->BindAction(ActionInput, ETriggerEvent::Completed, this, &ABallPlayer::ReleasedAction);

			EnhancedInputComponent->BindAction(SprintInput, ETriggerEvent::Triggered, this, &ABallPlayer::SprintIn);
			EnhancedInputComponent->BindAction(SprintInput, ETriggerEvent::Completed, this, &ABallPlayer::SprintOut);

			// Input Axis
			EnhancedInputComponent->BindAction(AxisInput, ETriggerEvent::Triggered, this, &ABallPlayer::PressedAxis);
			EnhancedInputComponent->BindAction(CameraAxisInput, ETriggerEvent::Triggered, this, &ABallPlayer::CameraAxisMovement);

		}

		if (APlayerController* PlayerController = Cast<APlayerController>(controller))
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			{
				Subsystem->AddMappingContext(DefaultMappingContext, 0);
			}
		}
	}
}

// Called every frame
void ABallPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator rot = SpringArm->GetRelativeRotation();
	FRotator actRot = this->GetActorRotation();
	rot.Yaw = actRot.Yaw;
	SpringArm->SetRelativeRotation(rot);


	
}

// Called to bind functionality to input
void ABallPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABallPlayer::PressedAction() {
	FVector pos = this->GetActorLocation();
	if(pos.Z < 100.f)
		Sphere->AddImpulse(FVector::UpVector * 100.f * Sphere->GetMass());

}

void ABallPlayer::ReleasedAction()
{

}

void ABallPlayer::PressedAxis(const FInputActionValue& Value)
{
	FVector2D v = Value.Get<FVector2D>();
	
	FVector d = { v.X, v.Y, 0.0 };
	FRotator rot = this->GetActorRotation();
	rot = rot.GetInverse();
	d = rot.RotateVector(d);

	FVector pos = this->GetActorLocation();
	pos.X += d.Y * velocity;
	pos.Y += d.X * velocity;
	this->SetActorLocation(pos);
	
	//UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("X:%f Y:%f"), v.X, v.Y), true, true, FColor::Cyan, 10.0f, TEXT("None"));
}

void ABallPlayer::CameraAxisMovement(const FInputActionValue& Value) {
	FVector2D v = Value.Get<FVector2D>();
	FRotator rot = SpringArm->GetRelativeRotation();
	rot.Yaw += v.X;
	if (rot.Pitch + v.Y < 0.f && rot.Pitch + v.Y > -89.f)
		rot.Pitch += v.Y;
	
	SpringArm->SetRelativeRotation(rot);

	FRotator actRot = this->GetActorRotation();
	actRot.Yaw += v.X;
	this->SetActorRotation(actRot);
	
}

void ABallPlayer::SprintIn() {
	velocity = 10.f;
	
}

void ABallPlayer::SprintOut()
{
	velocity = 5.f;
}


