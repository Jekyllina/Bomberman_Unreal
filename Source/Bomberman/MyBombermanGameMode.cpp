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