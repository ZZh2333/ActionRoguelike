// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyEventManager.generated.h"

/***
 该事件分发系统包含DispatherInterface、MyEventManager、MyDispathData三个类
 分别是事件分发接口、事件分发管理器、分发数据类
 ***/

UCLASS()
class ACTIONROGUELIKE_API UMyEventManager : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:

	//2.存放所有的订阅事件及其订阅者，用map数据结构
	static TMap<FString, TArray<UObject*>> AllListeners;

public:

	//3.添加订阅信息，要求两个参数（订阅的事件，订阅者对象指针）
	//8.添加宏命令：使得函数可被蓝图调用，下同
	UFUNCTION(BlueprintCallable, Category = "Event Dispather Utility")
		static void AddEventListener(FString EventName, UObject* Listener);

	//4.移除订阅信息
	UFUNCTION(BlueprintCallable, Category = "Event Dispather Utility")
		static void RemoveEventListener(FString EventName, UObject* Listener);

	//5.事件分发函数，返回值为错误信息，亦可使用void，参数为所要分发的事件和分发的数据
	UFUNCTION(BlueprintCallable, Category = "Event Dispather Utility")
		static FString DispathEvent(FString EventName, UObject* data);

	//6.工具类：创建新的资源（UObject）以供分发
	//9.BlueprintPure声明函数为pure函数，没有执行引脚
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Event Dispather Utility")
		static UObject* NewAsset(UClass* ClassType);


};
