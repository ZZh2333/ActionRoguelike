// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyDispathData.generated.h"

/**
 *
 */

 //16.添加BlueprintAble，表示该类可被蓝图继承
UCLASS(BlueprintAble)
class ACTIONROGUELIKE_API UMyDispathData : public UObject
{
	GENERATED_BODY()

public:
	//17.定义构造函数
	UMyDispathData();

	//18.定义参数，可被蓝图读取（BlueprintReadWrite）
	UPROPERTY(BlueprintReadWrite)
		int Param;
};
