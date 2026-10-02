// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile.h"
#include "GameFramework/Actor.h"
#include "Dash.generated.h"

UCLASS()
class TRAIN_API ADash : public AProjectile
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADash();

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* ProcParticleComp;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
