// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAbility.h"

////////////////////////////////////////////
bool UBaseAbility::Activate(FVector Location)
{
	if (inCooldownTime)
	{
		return false;
	}

	UWorld* World = GetWorld();
	if (IsValid(World) == false)
	{
		return false;
	}

	if (CooldownTime == 0.0f)
	{
		OnCooldownTimerEnded();
	}
	else
	{
		World->GetTimerManager().SetTimer(CooldownTimerHandle, this, &UBaseAbility::OnCooldownTimerEnded, CooldownTime, true);

	}
	return true;
}

void UBaseAbility::OnCooldownTimerEnded()
{
	inCooldownTime = false;
}

////////////////////////////////////////////