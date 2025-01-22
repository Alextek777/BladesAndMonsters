#include <engine/engine.h>


bool AnimatedGame::OnUserCreate()
{
    // Load the sprite sheet
    spriteSheet = new olc::Sprite("sprites/image.png");
    if (!spriteSheet)
        return false;

    return true;
}

bool AnimatedGame::OnUserUpdate(float fElapsedTime) 
{
    // Reset velocity
    velocity = { 0.0f, 0.0f };

    // Handle input for movement
    if (GetKey(olc::Key::W).bHeld) velocity.y = -1.0f;
    if (GetKey(olc::Key::S).bHeld) velocity.y =  1.0f;
    if (GetKey(olc::Key::A).bHeld) velocity.x = -1.0f;
    if (GetKey(olc::Key::D).bHeld) velocity.x =  1.0f;

    // Normalize velocity to ensure consistent speed
    if (velocity.mag() > 0)
        velocity = velocity.norm();

    // Update position
    position += velocity * speed * fElapsedTime;

    // Update animation if moving
    if (velocity.mag() > 0)
    {
        frameTimer += fElapsedTime;
        if (frameTimer >= frameDuration)
        {
            frameTimer -= frameDuration;
            currentFrame = (currentFrame + 1) % 4; // Assuming 4 frames of animation
        }
    }
    else
    {
        // Reset to the first frame when not moving
        currentFrame = 0;
    }

    // Clear screen
    Clear(olc::BLACK);

    // Draw the current frame
    DrawPartialSprite(position, spriteSheet, { currentFrame * frameWidth, 0 }, { frameWidth, frameHeight });

    return true;
}

bool AnimatedGame::OnUserDestroy()
{
    // Clean up
    delete spriteSheet;
    return true;
}