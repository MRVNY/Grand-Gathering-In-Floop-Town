// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SnowBallGameMode.generated.h"

/**
 * 
 */
UCLASS()
class COZYGAMEJAM2023_API ASnowBallGameMode : public AGameModeBase
{
	GENERATED_BODY()


protected:
	virtual void BeginPlay() override;

private:
	class ASnowBall* SnowBall;
};
