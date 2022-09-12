// Fill out your copyright notice in the Description page of Project Settings.


#include "ZHCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AZHCharacter::AZHCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//���ɱ���������õĴ��������ǽ�ڵ���ײ
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);

	//�������������֮��ľ��룿
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);


}

// Called when the game starts or when spawned
void AZHCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AZHCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

// Called every frame
void AZHCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AZHCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//��������ǰ�������ˡ���ͷƫ��
	PlayerInputComponent->BindAxis("MoveForward", this, &AZHCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
}

