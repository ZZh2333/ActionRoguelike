// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyEventManager.generated.h"

/***
 ���¼��ַ�ϵͳ����DispatherInterface��MyEventManager��MyDispathData������
 �ֱ����¼��ַ��ӿڡ��¼��ַ����������ַ�������
 ***/

UCLASS()
class ACTIONROGUELIKE_API UMyEventManager : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:

	//2.������еĶ����¼����䶩���ߣ���map���ݽṹ
	static TMap<FString, TArray<UObject*>> AllListeners;

public:

	//3.��Ӷ�����Ϣ��Ҫ���������������ĵ��¼��������߶���ָ�룩
	//8.��Ӻ����ʹ�ú����ɱ���ͼ���ã���ͬ
	UFUNCTION(BlueprintCallable, Category = "Event Dispather Utility")
		static void AddEventListener(FString EventName, UObject* Listener);

	//4.�Ƴ�������Ϣ
	UFUNCTION(BlueprintCallable, Category = "Event Dispather Utility")
		static void RemoveEventListener(FString EventName, UObject* Listener);

	//5.�¼��ַ�����������ֵΪ������Ϣ�����ʹ��void������Ϊ��Ҫ�ַ����¼��ͷַ�������
	UFUNCTION(BlueprintCallable, Category = "Event Dispather Utility")
		static FString DispathEvent(FString EventName, UObject* data);

	//6.�����ࣺ�����µ���Դ��UObject���Թ��ַ�
	//9.BlueprintPure��������Ϊpure������û��ִ������
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Event Dispather Utility")
		static UObject* NewAsset(UClass* ClassType);


};
