// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SMagicProjecttile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UParticleSystemComponent;

UCLASS()
class ACTIONROGUELIKE_API ASMagicProjecttile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASMagicProjecttile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//碰撞组件
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USphereComponent* SphereComp;

	//投射物组件（带出速度）
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UProjectileMovementComponent* MovementComp;

	//粒子系统组件
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UParticleSystemComponent* EffectComp;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
