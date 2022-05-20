// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBomb.h"
#include "MyBombermanPlayerController.h"

// Sets default values
AMyBomb::AMyBomb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyBomb::BeginPlay()
{
	Super::BeginPlay();
	
}

//void AMyBomb::KillPawn_Implementation(APlayerController* PlayerController)
//{
//	PlayerController->IsDead
//}

// Called every frame
void AMyBomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

