// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//����ӿ�ͷ�ļ�
#include "DispatherInterface.h"
#include "MyReceiverParent.h"
#include "MyReceiver_G.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API AMyReceiver_G : public AMyReceiverParent, public IDispatherInterface //��Ӽ̳��Խӿ�
{
	GENERATED_BODY()
	

protected:
	//1.��д����beginplay����beginplay�ж���
	virtual void BeginPlay() override;

public:
	//2.������interface�������BlueprintNativeEvent����C++ʵ�ֽӿڼ���
	virtual void OnReceiveEvent_Implementation(UObject* data) override;

	//n+1.��������
	virtual void BeginDestroy() override;

};
