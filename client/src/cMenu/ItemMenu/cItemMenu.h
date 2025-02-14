#pragma once

#include "../cMenu.h"

class cItemMenu : public cMenu {

public: 
    cItemMenu(olc::PixelGameEngine *gfx) : cMenu(gfx) {}

    virtual void DrawSelf(float fElapsedTime)override;
};