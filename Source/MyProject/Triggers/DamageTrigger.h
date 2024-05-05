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
	virtual void Action(AActor* InTarget) override;
	UPROPERTY(EditAnywhere)
	float Damage = 0.1f;
	//////////////////////////////////////////////////////
};
