#include "cAnimations.h"


void cAnimationHandler::load(string name, e_GraphicsState state, e_FactionDirection direction, string path, uint16_t frameCount, uint16_t frameWidth, uint16_t frameHight) {
    animations[name][state][direction] = Animation(frameCount, 
                                                   frameWidth, 
                                                   frameHight == 0 ? frameWidth : frameHight, 
                                                   new olc::Sprite(path));
}


AnimationFrame* cAnimationHandler::getAnimationFrame(string &name, e_GraphicsState state, e_FactionDirection direction, uint16_t counter) {
    return animations.at(name).at(state).at(direction).getFrame(counter);
}

uint16_t cAnimationHandler::getFrameCount(string &name, e_GraphicsState state, e_FactionDirection direction) {
    return animations.at(name).at(state).at(direction).getFrameCount();
}

// -------------------------------------------------------------------------------------------------------------------------------------------------

Animation::Animation(uint16_t frameCount, uint16_t frameWidth, uint16_t frameHeight, olc::Sprite *sprite) {
    frameVec = new AnimationFrame[frameCount];


    this->sprite = sprite;
    this->frameCount = frameCount;
    this->frameWidth = frameWidth;
    this->frameHeight = frameHeight;

    olc::Decal* decal = new olc::Decal(sprite);
    for (int i = 0; i < frameCount; i++) {
        frameVec[i].decal = decal;
        frameVec[i].ox = i * frameWidth;
        frameVec[i].oy = 0;
        frameVec[i].width = frameWidth;
        frameVec[i].height = frameHeight;
    }
}

uint16_t Animation::getFrameCount() {
    return frameCount;
}

// -------------------------------------------------------------------------------------------------------------------------------------------------

AnimationFrame* Animation::getFrame(uint16_t counter) {
    if (frameVec == nullptr || frameCount == 0 || &frameVec[counter % frameCount] == nullptr) {
        throw std::out_of_range("Invalid frame access.");
    }

    return &frameVec[counter % frameCount];
}

AnimationFrame::AnimationFrame(olc::Sprite* sprite, uint16_t ox, uint16_t oy, uint16_t width, uint16_t height) {
    this->decal = new olc::Decal(sprite);
    this->ox = ox;
    this->oy = oy; // TODO: might be unnececarry, all animations should start from upper corner
    this->width = width;
    this->height = height;
}

// -------------------------------------------------------------------------------------------------------------------------------------------------