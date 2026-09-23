// Fill out your copyright notice in the Description page of Project Settings.


#include "TrainCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
ATrainCharacter::ATrainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	ArmComp = CreateDefaultSubobject<USpringArmComponent>("ArmComp");
	ArmComp->SetupAttachment(RootComponent);
	ArmComp->bUsePawnControlRotation = true; 
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(ArmComp);
	
}

// Called when the game starts or when spawned
void ATrainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
		PC->PlayerCameraManager->ViewPitchMin = -60.f;
		PC->PlayerCameraManager->ViewPitchMax = 60.f;
	}
}

void ATrainCharacter::Move(const FInputActionValue& EventValue)
{
	FVector2D MovementVector = EventValue.Get<FVector2D>();
	
	AddMovementInput(GetActorForwardVector(), MovementVector.Y);
	AddMovementInput(GetActorRightVector(), MovementVector.X);
}

void ATrainCharacter::Look(const FInputActionValue& EventValue)
{
	FVector2D MovementVector = EventValue.Get<FVector2D>();
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Ma variable: %f"),  MovementVector.Y));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Ma variable: %f"),  MovementVector.X));

	}
	AddControllerYawInput(MovementVector.X);
	AddControllerPitchInput(MovementVector.Y * 0.5f);
}

// Called every frame
void ATrainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATrainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ATrainCharacter::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ATrainCharacter::Look);
	}
}

