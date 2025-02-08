#pragma once

#include <olcPixelGameEngine.h>
#include <string>
#include <map>

#include "consts/consts.h"

using namespace std;


struct Animation;
struct AnimationFrame;

class cAnimationHandler {
    map<string, map<e_GraphicsState, map<e_FactionDirection, Animation>>> animations;
public:
    void load(string name, e_GraphicsState state, e_FactionDirection direction, string path, uint16_t frameCount, uint16_t frameWidth, uint16_t frameHight = -1);

    AnimationFrame* getAnimationFrame(string &name, e_GraphicsState state, e_FactionDirection direction, uint16_t counter);
};


struct Animation {
    olc::Sprite *sprite;
    uint16_t frameCount;
    uint16_t frameWidth;
    uint16_t frameHeight;
    AnimationFrame* frameVec;
    Animation(){}

    Animation(uint16_t frameCount, uint16_t frameWidth, uint16_t frameHeight, olc::Sprite *sprite);
    AnimationFrame* getFrame(uint16_t counter);
};

struct AnimationFrame {
    olc::Decal* decal;
    uint16_t ox, oy;
    uint16_t width;
    uint16_t height;

    AnimationFrame(){}
    AnimationFrame(olc::Sprite* sprite, uint16_t ox, uint16_t oy, uint16_t width, uint16_t height);
};