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

//////////////////////////////////////////////////////

// Called when the game starts or when spawned
void ABaseTrigger::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMyProjectCharacter::StaticClass(), Actors);

	if (Actors.Num() > 0)
	{
		Target = Actors[0];
	}

	UWorld* World = GetWorld();
	if (IsValid(World) == false)
	{
		return;
	}
	FTimerHandle Timer;
	World->GetTimerManager().SetTimer(Timer, this, &ABaseTrigger::CustomTick, CustomTickRate, true);
	
}
void ABaseTrigger::CustomTick()
{
	if (IsValid(Target))
	{
		if ((GetActorLocation() - Target->GetActorLocation()).Length() < Range)
		{
			Action(Target);
		}
	}
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
void ABaseTrigger::Action(AActor* InTarget)
{
}
///////////////////////
void ABaseTrigger::ActionStart(AActor* InTarget)
{
}

void ABaseTrigger::ActionEnd(AActor* InTarget)
{
}

//////////////////////////////////////////////////////

// Called every frame
void ABaseTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}