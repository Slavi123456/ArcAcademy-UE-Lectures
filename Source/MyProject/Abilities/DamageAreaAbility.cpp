// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageAreaAbility.h"
#include "../Triggers/DamageTrigger.h"

bool UDamageAreaAbility::Activate(FVector Location)
{
	UWorld* World = GetWorld();
	if (IsValid(World) == false)
	{
		return false;
	}
	FActorSpawnParameters SpawnParamaters;
	//DamageTriggerClass = Cast<ADamageTrigger>(dA);
	SpawnParamaters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn; 

	AActor* Spawner = World->SpawnActor<AActor>(DamageTriggerClass, Location, Location.Rotation(), SpawnParamaters);
	
	if (IsValid(Spawner) == false)
	{
		return false ;
	}
	return true;
}

