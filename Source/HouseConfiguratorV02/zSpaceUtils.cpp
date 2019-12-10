// Fill out your copyright notice in the Description page of Project Settings.


#include "zSpaceUtils.h"

// Sets default values for this component's properties
UzSpaceUtils::UzSpaceUtils()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UzSpaceUtils::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UzSpaceUtils::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UzSpaceUtils::CreateUMeshFromZMesh(zObjMesh&_mesh, UProceduralMeshComponent* _UMesh)
{
	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FProcMeshTangent> Tangents;
	TArray<FVector2D> UV0;
	TArray<FLinearColor> VertexColors;

	zInt2DArray fTris;
	zFnMesh fnMesh(_mesh);
	fnMesh.getMeshTriangles(fTris);

	for (zItMeshVertex it(_mesh); !it.end(); it++)
	{
		zVector pos = it.getPosition();
		FVector vertex = FVector(pos.x, pos.y, pos.z);
		Vertices.Add(vertex);

		zVector norm = it.getNormal();
		Normals.Add(FVector(norm.x, norm.y, norm.z));

		//VertexColors.Add(FLinearColor(it.getColor().r, it.getColor().g, it.getColor().b, 1.0));
		VertexColors.Add(FLinearColor(1, 0, 0, 1));
	}

	for (int i = 0; i < fTris.size(); i++)
	{
		for (int j = 0; j < fTris[i].size(); j++)
		{
			Triangles.Add(fTris[i][j % fTris[i].size()]);
			Triangles.Add(fTris[i][(j + 1) % fTris[i].size()]);
			Triangles.Add(fTris[i][(j + 2) % fTris[i].size()]);
		}
	}

	_UMesh->CreateMeshSection_LinearColor(0, Vertices, Triangles, Normals, UV0, VertexColors, Tangents, true);

	// Enable collision data
	_UMesh->ContainsPhysicsTriMeshData(true);
}

