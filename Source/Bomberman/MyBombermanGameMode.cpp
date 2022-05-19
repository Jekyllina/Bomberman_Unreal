// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBombermanGameMode.h"

void AMyBombermanGameMode::DestroyPawn(APlayerController* PlayerController)
{
	FTransform Transform;
	APawn* CurrentPawn = PlayerController->GetPawn();
	
	if (CurrentPawn)
	{
		Transform = CurrentPawn->GetActorTransform();
	}

	APawn* NewPawn = GetWorld()->SpawnActor<APawn>(DestroyedPawn, Transform);

	if (NewPawn)
	{
		PlayerController->UnPossess();
		PlayerController->Possess(NewPawn);

		if (CurrentPawn)
		{
			CurrentPawn->Destroy();
		}
	}	
}

void AMyBombermanGameMode::RespawnPawn(APlayerController* PlayerController, FTransform Transform)
{
	APawn* CurrentPawn = PlayerController->GetPawn();
	
	APawn* NewPawn = GetWorld()->SpawnActor<APawn>(PlayingPawn, Transform);

	if (NewPawn)
	{
		PlayerController->UnPossess();
		PlayerController->Possess(NewPawn);

		if (CurrentPawn)
		{
			CurrentPawn->Destroy();
		}
	}
}

void AMyBombermanGameMode::SpawnBomb(FTransform Transform)
{
	UBlueprint* BombBlueprint = LoadObject<UBlueprint>(nullptr, TEXT("/Game/Bomb.Bomb"));
	
	if (BombBlueprint)
	{
		if (BombBlueprint->GeneratedClass->IsChildOf<AActor>())  
		{
			AActor* NewActor = GetWorld()->SpawnActor<AActor>(BombBlueprint->GeneratedClass, Transform);
		}
	}
}