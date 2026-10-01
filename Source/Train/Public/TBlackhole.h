// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TBlackhole.generated.h"

class UProjectileMovementComponent;
class USphereComponent;
class URadialForceComponent;
class UParticleSystemComponent;

UCLASS()
class TRAIN_API ATBlackhole : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ATBlackhole();

protected:
	
	UPROPERTY(VisibleAnywhere)
	USphereComponent* SphereComp;
	
	UPROPERTY(VisibleAnywhere)
	USphereComponent* DestroySphereComp;
	
	UPROPERTY(VisibleAnywhere)
	UProjectileMovementComponent* MovementComp;
	
	UPROPERTY(VisibleAnywhere)
	URadialForceComponent* RadialForceComp;
	
	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* ParticleComp;
	
	FTimerHandle Handler_Destroy;
	
	
	void DestroyTimer();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
