// Fill out your copyright notice in the Description page of Project Settings.


#include "WinTrigger.h"
#include "../MyProjectGameMode.h"

// Sets default values
AWinTrigger::AWinTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

//////////////////////////////////////////////////////
void AWinTrigger::ActionStart(AActor* InTarget)
{
	UWorld* World = GetWorld();
	if (IsValid(World) == false)
	{
		return;
	}

	AMyProjectGameMode* GameMode = Cast<AMyProjectGameMode>(World->GetAuthGameMode());

	if (IsValid(GameMode))
	{
		GameMode->EndGame(true);
	}
}

void AWinTrigger::ActionEnd(AActor* InTarget)
{
}


//////////////////////////////////////////////////////