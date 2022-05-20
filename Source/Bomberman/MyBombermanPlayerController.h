// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyBombermanPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_API AMyBombermanPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMyBombermanPlayerController();

	UFUNCTION(BlueprintCallable, Server, Reliable)  
	void DyingPawn();

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void RespawnPawn();

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void UseBomb(UBlueprint* Bomb);
	
	FTransform Transform;
	FTransform BombTransform;
};
