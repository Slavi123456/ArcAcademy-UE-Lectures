// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAbility.h"
#include "TeleportAbility.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UTeleportAbility : public UBaseAbility
{
	GENERATED_BODY()
public:
	virtual bool Activate(FVector Location) override;
private: 
	UPROPERTY(EditAnywhere)
	float MaxRange = 1000.0f;
	UPROPERTY(EditAnywhere)
	float MinRange = 300.0f;

	UPROPERTY()
	bool CanTeleportOverObstacle = false;
	UPROPERTY()
	bool DoesRetract = false;
};
