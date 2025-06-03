#pragma once
#include "RabbitPawn.h"
#include "Template/SubclassOf.h"
#include "UObject/ObjectMacros.h"

class ARabbitController;
class UCameraMeshComponent;
class UCameraShakeBase;

class ARabbitPlayer : public ARabbitPawn
{
    DECLARE_CLASS(ARabbitPlayer, ARabbitPawn)
    
public:
    ARabbitPlayer() = default;
    
    virtual void PostSpawnInitialize() override;

    virtual void BeginPlay() override;
    
    virtual void Tick(float DeltaTime) override;
    
    virtual UObject* Duplicate(UObject* InOuter) override;

    std::shared_ptr<RabbitCamera> GetRabbitCamera();

    virtual FVector GetActorForwardVector() const override;
    virtual FVector GetActorRightVector() const override;

    void Jump();

    void ZoomIn(float DeltaTime);
    void ZoomOut(float DeltaTime);
    
    bool IsADS() const { return bIsADS; }

    void TakePicture();
    
    void ToggleADS();

    void StartADS();
    void EndADS();

protected:
    void SetFOV(float FOV);
    float GetFOV() const;

    ARabbitController* GetRabbitController() const;

    virtual void OnRabbitBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp) override;
    virtual void OnRabbitEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp) override;
    
private:
    UCameraMeshComponent* CameraMesh = nullptr;
    
    std::shared_ptr<RabbitCamera> RabbitCam = nullptr;
    
    bool bIsADS = false;

    float DefaultFOV_ADS = 70.f;
    float DefaultFOV = 100.f;

    float MaxFOV_ADS = 90.f;
    float MinFOV_ADS = 30.f;
    float FOVChangeSpeed = 50.f;

    TSubclassOf<UCameraShakeBase> IdleCameraShake = UClass::FindClass("UIdleCameraShake");

    UCameraShakeBase* CameraShakeInstance = nullptr;
};

