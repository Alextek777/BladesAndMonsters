#pragma once

#include "../cMenu.h"

class cDefaultMenu : public cMenu {

public: 
    cDefaultMenu(olc::PixelGameEngine *gfx);
    virtual void DrawSelf(float fElapsedTime)override;
};