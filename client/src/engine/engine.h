#pragma once
#include <src/olcPixelGameEngine/olcPixelGameEngine.h>

class AnimatedGame : public olc::PixelGameEngine
{
public:
    AnimatedGame()
    {
        sAppName = "Animated Game";
    }

private:
    // Character position and velocity
    olc::vf2d position = { 50.0f, 50.0f };
    olc::vf2d velocity = { 0.0f, 0.0f };

    // Animation
    olc::Sprite* spriteSheet = nullptr; // Sprite sheet for animation
    int frameWidth = 32;
    int frameHeight = 32;
    int currentFrame = 0;
    float frameTimer = 0.0f;
    float frameDuration = 0.1f; // Time per frame in seconds

    // Movement speed
    float speed = 100.0f;

public:
    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;
    bool OnUserDestroy() override;
};