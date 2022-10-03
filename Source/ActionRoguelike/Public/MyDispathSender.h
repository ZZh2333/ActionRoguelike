// Fill out your copyright notice in the Description page of Project Settings.

/*
���������¼��ַ��������¼��ַ����ɼ̳��ڸ���
*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyDispathSender.generated.h"

UCLASS()
class ACTIONROGUELIKE_API AMyDispathSender : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyDispathSender();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
