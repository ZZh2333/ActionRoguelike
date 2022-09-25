// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LookDownKnight.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ALookDownKnight : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALookDownKnight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveX(float Value);
	void MoveY(float Value);


private:
	//ÒÆ¶¯²ÎÊý
	FVector Velocity;
	//»¥³âËø
	int IsMove = 0;
};
