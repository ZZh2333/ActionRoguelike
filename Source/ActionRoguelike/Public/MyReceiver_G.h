// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//引入接口头文件
#include "DispatherInterface.h"
#include "MyReceiverParent.h"
#include "MyReceiver_G.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API AMyReceiver_G : public AMyReceiverParent, public IDispatherInterface //添加继承自接口
{
	GENERATED_BODY()
	

protected:
	//1.重写父类beginplay，在beginplay中订阅
	virtual void BeginPlay() override;

public:
	//2.由于在interface中添加了BlueprintNativeEvent，供C++实现接口监听
	virtual void OnReceiveEvent_Implementation(UObject* data) override;

	//n+1.垃圾回收
	virtual void BeginDestroy() override;

};
