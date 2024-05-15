// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Public/Triggers/BaseTrigger.h"
#include "DamageTrigger.generated.h"

UCLASS()
class MYPROJECT_API ADamageTrigger : public ABaseTrigger
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADamageTrigger();

protected:

	//////////////////////////////////////////////////////
	virtual void ActionStart(AActor* InTarget) override;
	virtual void ActionEnd(AActor* InTarget) override;
	
	void DamageTick();
	UPROPERTY()
	AActor* Target;

	UPROPERTY(EditAnywhere)
	float Damage = 1.0f;
	UPROPERTY(EditAnywhere)
	float DamageTickRate = 1.0f;

	FTimerHandle DamageTimer;
	//////////////////////////////////////////////////////
};
