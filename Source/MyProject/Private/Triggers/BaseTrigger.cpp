// Fill out your copyright notice in the Description page of Project Settings.


#include "Triggers/BaseTrigger.h"
#include "Kismet/GameplayStatics.h"
#include "../MyProjectCharacter.h"
#include "Components/SphereComponent.h"

//////////////////////////////////////////////////////

// Sets default values
ABaseTrigger::ABaseTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//////////////////////////////////////////////////////
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollisionComponent"));
	SphereComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	SphereComponent->SetupAttachment(RootComponent);
	SphereComponent->OnComponentBeginOverlap.AddUniqueDynamic(this, &ABaseTrigger::OnOverlapBegin);
	SphereComponent->OnComponentEndOverlap.AddUniqueDynamic(this, &ABaseTrigger::OnOverlapEnd);
	//////////////////////////////////////////////////////

}
// Called when the game starts or when spawned
void ABaseTrigger::BeginPlay()
{
	Super::BeginPlay();
}

//////////////////////////////////////////////////////
void ABaseTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ActionStart(OtherActor);
}

void ABaseTrigger::OnOverlapEnd( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ActionEnd(OtherActor);
}
///////////////////////
void ABaseTrigger::ActionStart(AActor* InTarget)
{
}

void ABaseTrigger::ActionEnd(AActor* InTarget)
{
}

//////////////////////////////////////////////////////
