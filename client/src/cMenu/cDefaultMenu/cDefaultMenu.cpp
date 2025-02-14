#include "cDefaultMenu.h"


cDefaultMenu::cDefaultMenu(olc::PixelGameEngine *gfx) : cMenu(gfx) {
    pos  = olc::vi2d(4 * gfx->ScreenWidth() / 10, 2 * gfx->ScreenHeight() / 10);
    size = olc::vi2d(2 * gfx->ScreenWidth() / 10, 6 * gfx->ScreenHeight() / 10);
}

void cDefaultMenu::DrawSelf(float fElapsedTime) {

    gfx->FillRectDecal(pos, size,  olc::Pixel(38, 24, 24, 180));

}