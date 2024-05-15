// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "Components/SphereComponent.h"
#include "Engine/DamageEvents.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "../MyProject.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	SphereComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	SphereComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Overlap);
	RootComponent = SphereComponent; //??
	
	SphereComponent->OnComponentBeginOverlap.AddUniqueDynamic(this, &AProjectile::OnOverlap);
	
	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComponent"));
}

//////////////////////////////////////////////////////////////////
void AProjectile::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IsValid(OtherActor) == false)
	{
		return;
	}
	OtherActor->TakeDamage(Damage, FDamageEvent(UDamageType::StaticClass()), nullptr, nullptr);

	if (Destroy() == false)
	{
		UE_LOG(LogMyProject, Error, TEXT("Projectile.Destroy() == false"));
	}
	Destroy();
}
//////////////////////////////////////////////////////////////////


