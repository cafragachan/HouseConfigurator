// Fill out your copyright notice in the Description page of Project Settings.


#include "uAggregationManager.h"

#include "uHcUnit.h"


// Sets default values
AuAggregationManager::AuAggregationManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Utils = CreateDefaultSubobject<UzSpaceUtils>("ZSpace Utilities");

}

// Called when the game starts or when spawned
void AuAggregationManager::BeginPlay()
{
	Super::BeginPlay();

	structureType = zStructureType::zRHWC;

	hcManager.importMeshesFromDirectory(path);
	hcManager.createHousingUnits(structureType);
	//hcManager->importLayoutMeshesFromDirectory(pathLayoutFlat, pathLayoutVertical, pathLayoutlandscape);

	if (!HcUnitBase) return;
	for (auto& unit : hcManager.unitArray)
	{
		AuHcUnit* UnitTemp = GetWorld()->SpawnActor<AuHcUnit>(HcUnitBase, FVector(), FRotator());
		UnitTemp->InitialiseHcUnit(unit);

	}
}

// Called every frame
void AuAggregationManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AuAggregationManager::InitialiseAggregation()
{
	
}

