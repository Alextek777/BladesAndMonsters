#pragma once

#include "olcPixelGameEngine.h"

class cMenu {

public: 
    cMenu(olc::PixelGameEngine *gfx){
        this->gfx = gfx;

        pos  = olc::vi2d(2 * gfx->ScreenWidth() / 10, 2 * gfx->ScreenHeight() / 10);
        size = olc::vi2d(6 * gfx->ScreenWidth() / 10, 6 * gfx->ScreenHeight() / 10);
    }

    virtual void DrawSelf(float fElapsedTime) = 0;

protected:
    olc::PixelGameEngine *gfx;

    olc::vi2d pos;
    olc::vi2d size;
};