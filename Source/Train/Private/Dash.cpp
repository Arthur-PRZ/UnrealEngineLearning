// Fill out your copyright notice in the Description page of Project Settings.


#include "Dash.h"

#include "TrainCharacter.h"

// Sets default values
ADash::ADash()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	ProcParticleComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ProcParticleComp"));
	ProcParticleComp->SetupAttachment(RootComponent);

	
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->SetCollisionResponseToAllChannels(ECR_Block);
	SphereComp->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	
	MovementComp->InitialSpeed = 3000.0f;
	MovementComp->ProjectileGravityScale = 0.0f;

}

// Called when the game starts or when spawned
void ADash::BeginPlay()
{
	Super::BeginPlay();
	
	ProcParticleComp->Deactivate();
	SphereComp->IgnoreActorWhenMoving(GetInstigator(), true);
}

// Called every frame
void ADash::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

