// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageTrigger.h"
#include "Engine/DamageEvents.h"

// Sets default values
ADamageTrigger::ADamageTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ADamageTrigger::Action(AActor* InTarget)
{
	InTarget->TakeDamage(Damage, FDamageEvent(UDamageType::StaticClass()), nullptr, nullptr);
}
