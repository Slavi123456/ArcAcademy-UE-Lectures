// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Public/Triggers/BaseTrigger.h"
#include "SlowTrigger.generated.h"

UCLASS()
class MYPROJECT_API ASlowTrigger : public ABaseTrigger
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASlowTrigger();

protected:
	//////////////////////////////////////////////////////
	virtual void ActionStart(AActor* InTarget) override;
	virtual void ActionEnd(AActor* InTarget) override;
	
	UPROPERTY(EditAnywhere)
	float MaxWalkSpeed = 300.0f;
	UPROPERTY(EditAnywhere)
	float SlowingConst = 10.0f;
	float WalkSpeed = 300.0f;
	//////////////////////////////////////////////////////
public:	
	
};
