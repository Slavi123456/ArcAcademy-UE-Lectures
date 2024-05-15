// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseAbility.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UBaseAbility : public UObject
{
	GENERATED_BODY()
	////////////////////////////////////////////
public:
	virtual bool Activate(FVector Location);
private: 

	void OnCooldownTimerEnded();

	FTimerHandle CooldownTimerHandle;

	UPROPERTY(EditDefaultsOnly)
	float CooldownTime = 1.0f;
	bool inCooldownTime = false;

	////////////////////////////////////////////
protected:
};
