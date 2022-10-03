// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DispatherInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDispatherInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class ACTIONROGUELIKE_API IDispatherInterface
{
	GENERATED_BODY()

		// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	//1.定义收到广播后的处理函数
	//接口，不必在cpp中实现
	//7.添加宏命令：使得该接口在蓝图和cpp中都可以进行重写
	UFUNCTION(BlueprintNativeEvent,Category="Event Dispather Utility")
		void OnReceiveEvent(UObject* data);
};
