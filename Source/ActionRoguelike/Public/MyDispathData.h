// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyDispathData.generated.h"

/**
 *
 */

 //16.���BlueprintAble����ʾ����ɱ���ͼ�̳�
UCLASS(BlueprintAble)
class ACTIONROGUELIKE_API UMyDispathData : public UObject
{
	GENERATED_BODY()

public:
	//17.���幹�캯��
	UMyDispathData();

	//18.����������ɱ���ͼ��ȡ��BlueprintReadWrite��
	UPROPERTY(BlueprintReadWrite)
		int Param;
};
