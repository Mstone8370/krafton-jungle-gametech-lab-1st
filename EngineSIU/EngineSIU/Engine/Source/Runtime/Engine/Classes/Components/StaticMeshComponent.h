#pragma once
#include "Components/MeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/Asset/StaticMeshAsset.h"
#include "Engine/Contents/Runtime/Core/StaticMeshTypes.h"

enum class EPhotoType;
enum class EStaticMeshType;

class UStaticMeshComponent : public UMeshComponent
{
    DECLARE_CLASS(UStaticMeshComponent, UMeshComponent)

public:
    UStaticMeshComponent();

    virtual UObject* Duplicate(UObject* InOuter) override;


    virtual void GetProperties(TMap<FString, FString>& OutProperties) const override;

    virtual void SetProperties(const TMap<FString, FString>& InProperties) override;

    void SetselectedSubMeshIndex(const int& Value) { SelectedSubMeshIndex = Value; }
    int GetselectedSubMeshIndex() const { return SelectedSubMeshIndex; };

    virtual uint32 GetNumMaterials() const override;
    virtual UMaterial* GetMaterial(uint32 ElementIndex) const override;
    virtual uint32 GetMaterialIndex(FName MaterialSlotName) const override;
    virtual TArray<FName> GetMaterialSlotNames() const override;
    virtual void GetUsedMaterials(TArray<UMaterial*>& Out) const override;

    virtual int CheckRayIntersection(const FVector& InRayOrigin, const FVector& InRayDirection, float& OutHitDistance, FVector& OutHitNormal) const override;
    
    UStaticMesh* GetStaticMesh() const { return StaticMesh; }
    void SetStaticMesh(UStaticMesh* Value)
    { 
        StaticMesh = Value;
        if (StaticMesh == nullptr)
        {
            OverrideMaterials.SetNum(0);
            AABB = FBoundingBox(FVector::ZeroVector, FVector::ZeroVector);
        }
        else
        {
            OverrideMaterials.SetNum(Value->GetMaterials().Num());
            AABB = FBoundingBox(StaticMesh->GetRenderData()->BoundingBoxMin, StaticMesh->GetRenderData()->BoundingBoxMax);
        }
    }

    UPROPERTY_WITH_FLAGS(EditAnywhere,
        EStaticMeshType, MeshType, = EStaticMeshType::NONE;)

protected:
    UStaticMesh* StaticMesh = nullptr;
    int SelectedSubMeshIndex = -1;

private:
    EPhotoType PhotoType;
    
    

public:
    EPhotoType GetPhotoType();
    void SetPhotoType(EPhotoType Type);

    EStaticMeshType GetMeshType();
    void SetStMeshType(EStaticMeshType Type);
};
