// Fill out your copyright notice in the Description page of Project Settings.


#include "BoltAbility.h"
#include "../MyProjectCharacter.h"
#include "../Projectiles/Projectile.h"
#include "../MyProject.h"

bool UBoltAbility::Activate(FVector Location)
{
	Super::Activate(Location);
	
	UWorld* World = GetWorld();
	if (IsValid(World) == false)
	{
		return false;
	}
	FActorSpawnParameters SpawnParamaters;
	SpawnParamaters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	ACharacter* Owner = Cast<ACharacter>(GetOuter());
	if (IsValid(Owner) == false)
	{
		UE_LOG(LogMyProject, Error, TEXT("IsValid(Owner) == false"));
		return false;
	}
	FVector Direction = Location - Owner->GetActorLocation();
	Direction.Z = 0.0f;
	Direction.Normalize();
	
	FVector SpawnLocation = Owner->GetActorLocation() + Direction* 100.0f;

	AActor* Projectile = World->SpawnActor<AActor>(ProjectileClass, SpawnLocation, Direction.Rotation(), SpawnParamaters);
	
	if (IsValid(Projectile) == false)
	{
		UE_LOG(LogMyProject, Error, TEXT("IsValid(Projectile) == false"));
		return false;
	}
	return true;
}
