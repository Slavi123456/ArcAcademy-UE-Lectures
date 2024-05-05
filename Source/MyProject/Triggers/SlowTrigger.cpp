// Fill out your copyright notice in the Description page of Project Settings.


#include "SlowTrigger.h"
#include "../MyProjectCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../MyProject.h"

// Sets default values
ASlowTrigger::ASlowTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

//////////////////////////////////////////////////////
void ASlowTrigger::Action(AActor* InTarget)
{
	MaxWalkSpeed -= 0.1f;
	UE_LOG(LogMyProject, Log, TEXT("Speed %f"), MaxWalkSpeed);
	AMyProjectCharacter* Character = Cast<AMyProjectCharacter>(InTarget);
	if (IsValid(Character))
	{
		UCharacterMovementComponent* MovementComponent = Character->GetCharacterMovement();
		if (IsValid(MovementComponent))
		{
			MovementComponent->MaxWalkSpeed = MaxWalkSpeed;
		}
	}
}

//////////////////////////////////////////////////////
