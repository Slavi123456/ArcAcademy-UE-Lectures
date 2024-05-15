// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageTrigger.h"
#include "Engine/DamageEvents.h"

// Sets default values
ADamageTrigger::ADamageTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

//////////////////////////////////////////////////////
void ADamageTrigger::ActionStart(AActor* InTarget)
{
	Target = InTarget;
	UWorld* World = GetWorld();
	if (IsValid(World) == false)
	{
		return;
	}
	World->GetTimerManager().SetTimer(DamageTimer, this, &ADamageTrigger::DamageTick, DamageTickRate, true);
}

void ADamageTrigger::ActionEnd(AActor* InTarget)
{
	Target = nullptr;
	UWorld* World = GetWorld();
	if (IsValid(World) == false)
	{
		return;
	}
	World->GetTimerManager().ClearTimer(DamageTimer);
}

void ADamageTrigger::DamageTick()
{
	Target->TakeDamage(Damage, FDamageEvent(UDamageType::StaticClass()), nullptr, nullptr);
}
//////////////////////////////////////////////////////