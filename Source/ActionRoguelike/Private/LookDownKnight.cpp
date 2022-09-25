// Fill out your copyright notice in the Description page of Project Settings.


#include "LookDownKnight.h"

// Sets default values
ALookDownKnight::ALookDownKnight()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALookDownKnight::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ALookDownKnight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALookDownKnight::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//°´¼ü°ó¶¨
	PlayerInputComponent->BindAxis("MoveForward", this, &ALookDownKnight::MoveY);
	PlayerInputComponent->BindAxis("MoveRight", this, &ALookDownKnight::MoveX);
}

void ALookDownKnight::MoveX(float Value)
{
	Velocity.Y = Value;
	Velocity.X = 0;

	if (Value == 1) {
		//SetActorRotation(FRotator(0, 90, 0));
		AddMovementInput(Velocity);
	}
	else if (Value == -1) {
		//SetActorRotation(FRotator(0, -90, 0));
		AddMovementInput(Velocity);
	}
}

void ALookDownKnight::MoveY(float Value)
{
	Velocity.X = Value;
	Velocity.Y = 0;

	if (Value == 1) {
		//SetActorRotation(FRotator(0, 0, 0));
		AddMovementInput(Velocity);

	}
	else if (Value == -1) {
		//SetActorRotation(FRotator(0, -180, 0));
		AddMovementInput(Velocity);
	}
}

