// Fill out your copyright notice in the Description page of Project Settings.


#include "MyReceiver_G.h"
#include "Engine/Engine.h"
#include "MyDispathData.h"
#include "MyEventManager.h"
#include "TimerManager.h"

//3.ʵ��beginplay
void AMyReceiver_G::BeginPlay() {
	Super::BeginPlay();

	//5.�����¼�
	UMyEventManager::AddEventListener("MyTestDispathEvent", this);
	//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Green, FString::Printf(TEXT("G add .\n")));

	//n.5s��Ӵ�����
	//FTimerHandle TimerHandle;
	//auto f = [this]() {
	//	UMyEventManager::RemoveEventListener("MyTestDispathEvent", this);
	//};
	//GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda(f), 5.0f, false);

}

//4.����ӿ��¼������յ��ַ�ʱ����
void AMyReceiver_G::OnReceiveEvent_Implementation(UObject* data)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Green, FString::Printf(TEXT("%i"), Cast<UMyDispathData>(data)->Param));
}

//n+2.��������ʵ��
void AMyReceiver_G::BeginDestroy()
{
	//��remove����super
	UMyEventManager::RemoveEventListener("MyTestDispathEvent", this);
	Super::BeginDestroy();
}
