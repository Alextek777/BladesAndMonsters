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


struct AnimationFrame {
    olc::Decal* decal;
    uint16_t ox, oy;
    uint16_t width;
    uint16_t height;


    AnimationFrame(){}

    AnimationFrame(olc::Sprite* sprite, uint16_t ox, uint16_t oy, uint16_t width, uint16_t height) {
        this->decal = new olc::Decal(sprite);
        this->ox = ox;
        this->oy = oy; // TODO: might be unnececarry, all animations should start from upper corner
        this->width = width;
        this->height = height;
    }
};


struct Animation {
    olc::Sprite *sprite;
    uint16_t frameCount;
    uint16_t frameWidth;
    uint16_t frameHeight;
    AnimationFrame* frameVec;
    Animation(){}

    Animation(uint16_t frameCount, uint16_t frameWidth, uint16_t frameHeight, olc::Sprite *sprite) {
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

    AnimationFrame* getFrame(uint16_t counter) {
        if (frameVec == nullptr || frameCount == 0 || &frameVec[counter % frameCount] == nullptr) {
            throw std::out_of_range("Invalid frame access.");
        }

        return &frameVec[counter % frameCount];
    }
};
