// Fill out your copyright notice in the Description page of Project Settings.


#include "TeleportAbility.h"
#include "../MyProjectCharacter.h"
#include "../MyProject.h"
#include "NavigationPath.h"
#include "NavigationSystem.h"

bool UTeleportAbility::Activate(FVector Location)
{
	ACharacter* Character = Cast<ACharacter>(GetOuter());
	if (IsValid(Character) == false)
	{
		UE_LOG(LogMyProject, Error, TEXT("IsValid(Character) == false"));
		return false;
	}
	FVector characterLoc = Character->GetActorLocation();
	float distanceToLocation = (Location - characterLoc).Length();
	UE_LOG(LogMyProject, Error, TEXT("distanceToLocation = %f"), distanceToLocation);

	if (distanceToLocation < MinRange || distanceToLocation > MaxRange)
	{
		UE_LOG(LogMyProject, Error, TEXT("distanceToLocation < MinRange && distanceToLocation > MaxRange"));
		return false;
	}

	UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	if (IsValid(NavSys) == false)
	{
		return false;
	}
	UWorld* World = GetWorld();
	if (IsValid(World) == false)
	{
		return false;
	}
	UNavigationPath* NavPath = NavSys->FindPathToLocationSynchronously(World, characterLoc, Location);
	if (IsValid(NavPath) && NavPath->IsPartial() == false)
	{
		Character->SetActorLocation(Location);

		return true;
	}
	else
	{
		UE_LOG(LogMyProject, Error, TEXT("IsValid(NavPath) == false && NavPath->IsPartial() == false"));
		return false;
	}

}
