// Fill out your copyright notice in the Description page of Project Settings.


#include "MyReceiver_G.h"
#include "Engine/Engine.h"
#include "MyDispathData.h"
#include "MyEventManager.h"
#include "TimerManager.h"

//3.实现beginplay
void AMyReceiver_G::BeginPlay() {
	Super::BeginPlay();

	//5.订阅事件
	UMyEventManager::AddEventListener("MyTestDispathEvent", this);
	//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Green, FString::Printf(TEXT("G add .\n")));

	//n.5s后接触监听
	//FTimerHandle TimerHandle;
	//auto f = [this]() {
	//	UMyEventManager::RemoveEventListener("MyTestDispathEvent", this);
	//};
	//GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda(f), 5.0f, false);

}

//4.定义接口事件，当收到分发时操作
void AMyReceiver_G::OnReceiveEvent_Implementation(UObject* data)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Green, FString::Printf(TEXT("%i"), Cast<UMyDispathData>(data)->Param));
}

//n+2.垃圾回收实现
void AMyReceiver_G::BeginDestroy()
{
	//先remove，后super
	UMyEventManager::RemoveEventListener("MyTestDispathEvent", this);
	Super::BeginDestroy();
}
