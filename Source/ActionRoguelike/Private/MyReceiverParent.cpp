// Fill out your copyright notice in the Description page of Project Settings.


#include "MyReceiverParent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AMyReceiverParent::AMyReceiverParent()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));
	//RootComponent = Cube;

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	//static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("Material'/Engine/BasicShapes/Sphere.Sphere'"));
	//if (StaticMeshAsset.Succeeded() && MaterialAsset.Succeeded()) {
	//	Cube->SetStaticMesh(StaticMeshAsset.Object);
	//	Cube->SetMaterial(0, MaterialAsset.Object);
	//}
}

// Called when the game starts or when spawned
void AMyReceiverParent::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyReceiverParent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

