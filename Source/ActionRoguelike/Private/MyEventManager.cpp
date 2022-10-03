// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEventManager.h"
//10.添加头文件
#include "DispatherInterface.h"
#include "Engine.h"

//11.初始化TMap
TMap<FString, TArray<UObject*>> UMyEventManager::AllListeners;

void UMyEventManager::AddEventListener(FString EventName, UObject* Listener)
{
	//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Purple, FString::Printf(TEXT("begin to add sub. \n")));

	//12.实现添加订阅者
	//无效订阅，直接返回
	if (EventName == ""
		|| Listener == nullptr
		|| !Listener->IsValidLowLevel()
		|| !Listener->GetClass()->ImplementsInterface(UDispatherInterface::StaticClass()))
		return;

	//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Purple, FString::Printf(TEXT("end add sub. \n")));

	//判断是否存在该事件
	TArray<UObject*>* arr = UMyEventManager::AllListeners.Find(EventName);
	if (arr == nullptr || arr->Num() == 0) {
		//新事件
		TArray<UObject*> NewArr = { Listener };
		UMyEventManager::AllListeners.Add(EventName, NewArr);
	}
	else {
		//直接添加
		arr->Add(Listener);
	}
}

void UMyEventManager::RemoveEventListener(FString EventName, UObject* Listener)
{
	//13.移除事件的订阅者
	TArray<UObject*>* arr = UMyEventManager::AllListeners.Find(EventName);

	if (arr != nullptr && arr->Num() != 0) {
		arr->Remove(Listener);
	}
}

FString UMyEventManager::DispathEvent(FString EventName, UObject* data)
{
	//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Purple, FString::Printf(TEXT("%i"), 102));

	//14.进行事件分发
	TArray<UObject*>* arr = UMyEventManager::AllListeners.Find(EventName);
	if (arr == nullptr || arr->Num() == 0) {
		//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Purple, FString::Printf(TEXT("%i"), 104));
		return "'" + EventName + "' No Listener.";
	}

	//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Purple, FString::Printf(TEXT("%i"), 103));

	FString ErrorInfo = "\n";

	for (int i = 0; i < arr->Num(); i++) {
		UObject* obj = (*arr)[i];
		//安全检查
		if (obj == nullptr || !obj->IsValidLowLevel() || !obj->GetClass()->ImplementsInterface(UDispatherInterface::StaticClass())) {
			arr->RemoveAt(i);
			i--;
		}
		else {
			//接口名
			UFunction* Fun = obj->FindFunction("OnReceiveEvent");
			//安全检查
			if (Fun==nullptr || !Fun->IsValidLowLevel()) {
				ErrorInfo += "'" + obj->GetName() + "' No 'OnReceiveEvent' Function. \n";
			}
			else {
				//执行函数（函数+参数）
				obj->ProcessEvent(Fun, &data);
			}
		}
	}
	//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Purple, FString::Printf(TEXT("%i"),102));

	return ErrorInfo;
}

UObject* UMyEventManager::NewAsset(UClass* ClassType)
{
	//15.新建资源工具函数
	//NewObjec需要引入头文件"engine.h"
	UObject* obj = NewObject<UObject>(GetTransientPackage(), ClassType);
	return obj;
}
