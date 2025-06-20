
#pragma once
#include "PrimitiveComponent.h"

enum class EShapeType : uint8
{
    Box,
    Sphere,
    Capsule,

    Max,
};

class UShapeComponent : public UPrimitiveComponent
{
    DECLARE_CLASS(UShapeComponent, UPrimitiveComponent)    

public:
    UShapeComponent();

    virtual void TickComponent(float DeltaTime) override;
    
    FColor ShapeColor = FColor(180, 180, 180, 255);
    bool bDrawOnlyIfSelected = true;

    EShapeType GetShapeType() const { return ShapeType; }
    UPROPERTY(EditAnywhere,
    bool, bIsOverlapEnabled ,= true;
        )
protected:
    EShapeType ShapeType = EShapeType::Max;
};
