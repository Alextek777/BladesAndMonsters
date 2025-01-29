#include "cAnimations.h"


void cAnimationHandler::load(string name, e_GraphicsState state, e_FactionDirection direction, uint16_t frameCount, uint16_t frameSize, string path) {
    animations[name][state][direction] = Animation(frameCount, frameSize, new olc::Sprite(path));
}


AnimationFrame* cAnimationHandler::getAnimationFrame(string &name, e_GraphicsState state, e_FactionDirection direction, uint16_t counter) {
    return animations.at(name).at(state).at(direction).getFrame(counter);
}