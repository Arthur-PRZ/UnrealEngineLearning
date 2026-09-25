// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplosiveBarrel.h"
#include "MagicProjectile.h"
#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
AExplosiveBarrel::AExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	RootComponent = MeshComp;
	MeshComp->OnComponentHit.AddDynamic(this, &AExplosiveBarrel::Explose);

	RadialForceComp = CreateDefaultSubobject<URadialForceComponent>("RadialForceComp");
	RadialForceComp->SetupAttachment(RootComponent);
	RadialForceComp->Radius = 1500.0f;
	RadialForceComp->ImpulseStrength = 300000.0f;
	RadialForceComp->Falloff = RIF_Linear;
	RadialForceComp->AddCollisionChannelToAffect(ECC_PhysicsBody);
	
	MeshComp->SetCollisionProfileName(TEXT("Barrel"));
	MeshComp->SetSimulatePhysics(true);
}

void AExplosiveBarrel::Explose(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
		if (OtherActor)
		{
			if (AMagicProjectile* Projectile = Cast<AMagicProjectile>(OtherActor))
			{
				RadialForceComp->FireImpulse();
				OtherActor->Destroy();
				Destroy();
			}
		}
}

// Called when the game starts or when spawned
void AExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

