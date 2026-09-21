// Fill out your copyright notice in the Description page of Project Settings.


#include "TrainCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ATrainCharacter::ATrainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	ArmComp = CreateDefaultSubobject<USpringArmComponent>("ArmComp");
	ArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(ArmComp);
}

// Called when the game starts or when spawned
void ATrainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
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

}

