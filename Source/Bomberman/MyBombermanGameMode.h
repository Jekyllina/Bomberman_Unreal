// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyBombermanGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_API AMyBombermanGameMode : public AGameModeBase
{
	GENERATED_BODY()

	AMyBombermanGameMode();

	UPROPERTY()
	TMap<UNetConnection*, FNetTestPlayer> KnownPlayers;
};
