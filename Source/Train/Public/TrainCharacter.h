// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "TrainCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UInputMappingContext;
class UInputAction;

UCLASS()
class TRAIN_API ATrainCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ProjectileClass;
	
public:
	// Sets default values for this character's properties
	ATrainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;
	
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* ArmComp;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* DefaultMappingContext;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* PrimaryAttackAction;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* JumpAction;

	void PrimaryAttack();
	void Jump();
	void Move(const FInputActionValue& EventValue);
	void Look(const FInputActionValue& EventValue);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
