#include "cAnimations.h"


void cAnimationHandler::load(string name, e_GraphicsState state, e_FactionDirection direction, string path, uint16_t frameCount, uint16_t frameWidth, uint16_t frameHight) {
    frameHight = frameWidth == -1 ? frameWidth : frameHight;

    animations[name][state][direction] = Animation(frameCount, frameWidth, frameHight, new olc::Sprite(path));
}


AnimationFrame* cAnimationHandler::getAnimationFrame(string &name, e_GraphicsState state, e_FactionDirection direction, uint16_t counter) {
    return animations.at(name).at(state).at(direction).getFrame(counter);
}