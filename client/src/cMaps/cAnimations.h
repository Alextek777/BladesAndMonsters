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
    void load(string name, e_GraphicsState state, e_FactionDirection direction, uint16_t frameCount, uint16_t frameSize, string path);

    AnimationFrame* getAnimationFrame(string &name, e_GraphicsState state, e_FactionDirection direction, uint16_t counter);
};


struct AnimationFrame {
    olc::Sprite* sprite;
    uint16_t ox, oy;
    uint16_t frameSize;

    AnimationFrame(){}

    AnimationFrame(olc::Sprite* sprite, uint16_t ox, uint16_t oy, uint16_t frameSize) {
        this->sprite = sprite;
        this->ox = ox;
        this->oy = oy; // todo: might be unnececarry, all animations should start from upper corner
        this->frameSize = frameSize;
    }
};


struct Animation {
    olc::Sprite *sprite;
    uint16_t frameCount;
    uint16_t frameSize;
    AnimationFrame* frameVec;
    Animation(){}

    Animation(uint16_t frameCount, uint16_t frameSize, olc::Sprite *sprite) {
        frameVec = new AnimationFrame[frameCount];


        this->sprite = sprite;
        this->frameCount = frameCount;
        this->frameSize = frameSize;


        for (int i = 0; i < frameCount; i++) {
            frameVec[i].sprite = sprite;
            frameVec[i].ox = i * frameSize;
            frameVec[i].oy = 0;
            frameVec[i].frameSize = frameSize;
        }
    }

    AnimationFrame* getFrame(uint16_t counter) {
        if (frameVec == nullptr || frameCount == 0 || &frameVec[counter % frameCount] == nullptr) {
            throw std::out_of_range("Invalid frame access.");
        }

        return &frameVec[counter % frameCount];
    }
};
