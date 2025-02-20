#pragma once

#include "../cMenu.h"

class cInventory : public cMenu {
    olc::Sprite* widget;
    olc::Decal* decal;
public: 
    cInventory(olc::PixelGameEngine *gfx) : cMenu(gfx) {
        widget = new olc::Sprite("widgets/inventory.png");
        decal = new olc::Decal(widget);
    }
    virtual void DrawSelf(float fElapsedTime)override;
};