// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TGameplayInterface.h"
#include "GameFramework/Actor.h"
#include "TItemChest.generated.h"

UCLASS()
class TRAIN_API ATItemChest : public AActor, public ITGameplayInterface
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere)
	float TargetPitch;
	
	void Interact_Implementation(APawn* InstigatorPawn);
	
public:	
	// Sets default values for this actor's properties
	ATItemChest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere);
	UStaticMeshComponent* BaseMesh;
	
	UPROPERTY(VisibleAnywhere);
	UStaticMeshComponent* LidMesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
