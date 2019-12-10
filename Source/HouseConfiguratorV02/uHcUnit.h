// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#define ZSPACE_STATIC_LIBRARY
#define ZSPACE_UNREAL_INTEROP
#define USING_CLR

#include <headers/zApp/include/zObjects.h>
#include <headers/zApp/include/zFnSets.h>
#include <headers/zApp/include/zHousing.h>

using namespace zSpace;


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "zSpaceUtils.h"
#include "ProceduralMeshComponent.h"

#include "uHcUnit.generated.h"

UCLASS()
class HOUSECONFIGURATORV02_API AuHcUnit : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AuHcUnit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	////zCode

private:

	//corresponding zSpace unit
	zHcUnit* hcUnit;

protected:

	//zSpace Utility Methods
	UzSpaceUtils* Utils;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UProceduralMeshComponent* UMesh;

public:

	//SET METHODS

	//set the corresponding zspace hcUnit
	void InitialiseHcUnit(zHcUnit& _hcUnit);

};
