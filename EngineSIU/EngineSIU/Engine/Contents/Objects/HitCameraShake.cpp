﻿#include "HitCameraShake.h"

#include "Camera/Shakes/WaveOscillatorCameraShakePattern.h"

UHitCameraShake::UHitCameraShake()
{
    UWaveOscillatorCameraShakePattern* Pattern = new UWaveOscillatorCameraShakePattern();
    Pattern->Duration = 0.3f;
    Pattern->BlendInTime = 0.f;
    Pattern->BlendOutTime = 0.2f;

    // Rotation
    Pattern->RotationAmplitudeMultiplier = 1.f;
    Pattern->RotationFrequencyMultiplier = 1.f;
    
    Pattern->Yaw.Amplitude = 3.f;
    Pattern->Yaw.Frequency = 10.f;

    Pattern->Pitch.Amplitude = 8.0f;
    Pattern->Pitch.Frequency = 6.f;

    Pattern->Roll.Amplitude = 1.0f;
    Pattern->Roll.Frequency = 12.f;

    // Location
    Pattern->LocationAmplitudeMultiplier = 0.f;
    Pattern->LocationFrequencyMultiplier = 1.f;

    Pattern->X.Amplitude = 0.f;
    Pattern->X.Frequency = 1.f;

    Pattern->Y.Amplitude = 0.0f;
    Pattern->Y.Frequency = 1.f;

    Pattern->Z.Amplitude = 0.0f;
    Pattern->Z.Frequency = 1.f;
    
    SetRootShakePattern(Pattern);
}
