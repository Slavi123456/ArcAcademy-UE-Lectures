// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAbility.h"
#include "DamageAreaAbility.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class MYPROJECT_API UDamageAreaAbility : public UBaseAbility
{
	GENERATED_BODY()

public: 
	virtual bool Activate(FVector Location) override;
private: 
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class ADamageTrigger> DamageTriggerClass;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AProjectile> ProjectileClass;

};
