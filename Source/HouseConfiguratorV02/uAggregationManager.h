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

#include "uAggregationManager.generated.h"


UCLASS()
class HOUSECONFIGURATORV02_API AuAggregationManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AuAggregationManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	////zCode

private:

	string path = "C:/Users/cesar.fragachan/Desktop/zJson4";
	string pathLayoutVertical = "C:/Users/cesar.fragachan/Desktop/zJsonComplete/layout/vertical";
	string pathLayoutlandscape = "C:/Users/cesar.fragachan/Desktop/zJsonComplete/layout/landscape";
	string pathLayoutFlat = "C:/Users/cesar.fragachan/Desktop/zJsonComplete/layout/flat";


protected:

	//zSpace Utility Methods
	UzSpaceUtils* Utils;

	//zSpaceHcAggregation object
	zHcAggregation hcManager;

	//structure type
	zStructureType structureType;

	UFUNCTION(BlueprintCallable, Category = "ZHCODE")
	void InitialiseAggregation();

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AuHcUnit> HcUnitBase = nullptr;





};
