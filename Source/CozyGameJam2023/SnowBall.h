// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SnowBall.generated.h"

UCLASS()
class COZYGAMEJAM2023_API ASnowBall : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASnowBall();

	UFUNCTION(BlueprintCallable, Category="Object")
	void OnHitObject(float IncreaseModifCoef,AAbsorbableObject* AbsorbedObject);

	UFUNCTION(BlueprintCallable, Category="Absorption")
	void OnOverlapAbsorbable(AAbsorbableObject* AbsorbedObject);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	//collider
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Components")
	class USphereComponent* SphereComp;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Components")
	class UStaticMeshComponent* Mesh;

	// Absorbing object list
	TArray<AAbsorbableObject*> AbsorbedObjectList;
	/*
	//Root
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* Root;

	//Top down camera/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	//Spring Arm positioning the camera above the character
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArmComponent;
	*/

	void MoveForward(float axisValue);
	void MoveRight(float axisValue);
	void Grow(float GrowModifCoef, float SpeedCoef);
	void Grow(float ModifGrowCoef);
	void Grow(const AAbsorbableObject* AbsorbedObject);
	void GrowTest();
	bool CanAbsorbObject(const AAbsorbableObject* AbsorbableObject) const;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Movement")
	float InitialSpeed = 60000.0f;

	float Speed;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Movement")
	float TestGrowModifRate = 0.5f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Movement")
	float TestSpeedModifRate = 0.1f;

	float CurrentSphereRadius=0.0f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "AbsorbSystem")
	float SmallAbsorbRadius;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "AbsorbSystem")
	float MidAbsorbRadius;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "AbsorbSystem")
	float BigAbsorbRadius;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "AbsorbSystem")
	float HugeAbsorbRadius;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "AbsorbSystem")
	float EnormousAbsorbRadius;
};
