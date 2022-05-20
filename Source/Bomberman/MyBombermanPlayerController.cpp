// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBombermanPlayerController.h"
#include "MyBombermanGameMode.h"

AMyBombermanPlayerController::AMyBombermanPlayerController()
{
	bShowMouseCursor = true;
}

void AMyBombermanPlayerController::DyingPawn_Implementation()
{	
	APawn* CurrentPawn = this->GetPawn();

	if (CurrentPawn)
	{
		Transform = CurrentPawn->GetActorTransform();
	}

	AMyBombermanGameMode* GameMode = GetWorld()->GetAuthGameMode<AMyBombermanGameMode>();

	if (GameMode)
	{		
		GameMode->DestroyPawn(this);
	}
}

void AMyBombermanPlayerController::RespawnPawn_Implementation()
{
	AMyBombermanGameMode* GameMode = GetWorld()->GetAuthGameMode<AMyBombermanGameMode>();

	if (GameMode)
	{
		GameMode->RespawnPawn(this, Transform);
	}
}

void AMyBombermanPlayerController::UseBomb_Implementation(UBlueprint* Bomb)
{	
	APawn* CurrentPawn = this->GetPawn();
	BombTransform = CurrentPawn->GetActorTransform();
	BombTransform.AddToTranslation(FVector(0, 0, -70));

	AActor* BombActor = GetWorld()->SpawnActor<AActor>(Bomb->GeneratedClass, BombTransform);
}