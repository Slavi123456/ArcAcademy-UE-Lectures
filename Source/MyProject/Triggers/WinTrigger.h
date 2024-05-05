// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Public/Triggers/BaseTrigger.h"
#include "WinTrigger.generated.h"

UCLASS()
class MYPROJECT_API AWinTrigger : public ABaseTrigger
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWinTrigger();
	
	//////////////////////////////////////////////////////
	virtual void Action(AActor* InTarget) override;
	//////////////////////////////////////////////////////

};
