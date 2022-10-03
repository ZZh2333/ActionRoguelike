// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEventManager.h"
//10.���ͷ�ļ�
#include "DispatherInterface.h"
#include "Engine.h"

//11.��ʼ��TMap
TMap<FString, TArray<UObject*>> UMyEventManager::AllListeners;

void UMyEventManager::AddEventListener(FString EventName, UObject* Listener)
{
	//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Purple, FString::Printf(TEXT("begin to add sub. \n")));

	//12.ʵ����Ӷ�����
	//��Ч���ģ�ֱ�ӷ���
	if (EventName == ""
		|| Listener == nullptr
		|| !Listener->IsValidLowLevel()
		|| !Listener->GetClass()->ImplementsInterface(UDispatherInterface::StaticClass()))
		return;

	//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Purple, FString::Printf(TEXT("end add sub. \n")));

	//�ж��Ƿ���ڸ��¼�
	TArray<UObject*>* arr = UMyEventManager::AllListeners.Find(EventName);
	if (arr == nullptr || arr->Num() == 0) {
		//���¼�
		TArray<UObject*> NewArr = { Listener };
		UMyEventManager::AllListeners.Add(EventName, NewArr);
	}
	else {
		//ֱ�����
		arr->Add(Listener);
	}
}

void UMyEventManager::RemoveEventListener(FString EventName, UObject* Listener)
{
	//13.�Ƴ��¼��Ķ�����
	TArray<UObject*>* arr = UMyEventManager::AllListeners.Find(EventName);

	if (arr != nullptr && arr->Num() != 0) {
		arr->Remove(Listener);
	}
}

FString UMyEventManager::DispathEvent(FString EventName, UObject* data)
{
	//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Purple, FString::Printf(TEXT("%i"), 102));

	//14.�����¼��ַ�
	TArray<UObject*>* arr = UMyEventManager::AllListeners.Find(EventName);
	if (arr == nullptr || arr->Num() == 0) {
		//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Purple, FString::Printf(TEXT("%i"), 104));
		return "'" + EventName + "' No Listener.";
	}

	//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Purple, FString::Printf(TEXT("%i"), 103));

	FString ErrorInfo = "\n";

	for (int i = 0; i < arr->Num(); i++) {
		UObject* obj = (*arr)[i];
		//��ȫ���
		if (obj == nullptr || !obj->IsValidLowLevel() || !obj->GetClass()->ImplementsInterface(UDispatherInterface::StaticClass())) {
			arr->RemoveAt(i);
			i--;
		}
		else {
			//�ӿ���
			UFunction* Fun = obj->FindFunction("OnReceiveEvent");
			//��ȫ���
			if (Fun==nullptr || !Fun->IsValidLowLevel()) {
				ErrorInfo += "'" + obj->GetName() + "' No 'OnReceiveEvent' Function. \n";
			}
			else {
				//ִ�к���������+������
				obj->ProcessEvent(Fun, &data);
			}
		}
	}
	//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Purple, FString::Printf(TEXT("%i"),102));

	return ErrorInfo;
}

UObject* UMyEventManager::NewAsset(UClass* ClassType)
{
	//15.�½���Դ���ߺ���
	//NewObjec��Ҫ����ͷ�ļ�"engine.h"
	UObject* obj = NewObject<UObject>(GetTransientPackage(), ClassType);
	return obj;
}
