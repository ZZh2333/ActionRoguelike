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

	//1.�����յ��㲥��Ĵ�����
	//�ӿڣ�������cpp��ʵ��
	//7.��Ӻ����ʹ�øýӿ�����ͼ��cpp�ж����Խ�����д
	UFUNCTION(BlueprintNativeEvent,Category="Event Dispather Utility")
		void OnReceiveEvent(UObject* data);
};
