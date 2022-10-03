// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDispathSender.h"
#include "MyEventManager.h"
#include "MyDispathData.h"
#include "Engine/Engine.h"
#include "TimerManager.h"

// Sets default values
AMyDispathSender::AMyDispathSender()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyDispathSender::BeginPlay()
{
	Super::BeginPlay();
	//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Black, FString::Printf(TEXT("%i"), 1002));

	//2.引入定时器，定时发送
	FTimerHandle TimerHandle;
	auto f = []() {
		//1.创建分发数据
		UMyDispathData* data = Cast<UMyDispathData>(UMyEventManager::NewAsset(UMyDispathData::StaticClass()));
		int tmp = FMath::RandRange(0, 255);
		data->Param = tmp;
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Black, FString::Printf(TEXT("%i"), tmp));
		UMyEventManager::DispathEvent("MyTestDispathEvent", data);
	};
	//3.设置定时器重复时间
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda(f), 3.0f, true);

}

// Called every frame
void AMyDispathSender::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyDispathSender::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

