#pragma once

#include "../cMenu.h"

class cInventory : public cMenu {

public: 
    cInventory(olc::PixelGameEngine *gfx) : cMenu(gfx) {}
    virtual void DrawSelf(float fElapsedTime)override;
};