// Fill out your copyright notice in the Description page of Project Settings.


#include "uHcUnit.h"

// Sets default values
AuHcUnit::AuHcUnit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UMesh = CreateDefaultSubobject<UProceduralMeshComponent>("ProceduralMesh");
}

// Called when the game starts or when spawned
void AuHcUnit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AuHcUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AuHcUnit::InitialiseHcUnit(zHcUnit & _hcUnit)
{
	hcUnit = &_hcUnit;

	zFnMesh tempFnMesh(*hcUnit->inUnitMeshObj);
	UE_LOG(LogTemp, Warning, TEXT("num of polys: %i"), tempFnMesh.numPolygons());

	Utils->CreateUMeshFromZMesh(*hcUnit->inUnitMeshObj, UMesh);

}

