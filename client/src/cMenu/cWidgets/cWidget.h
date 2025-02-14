#pragma once

#include <olcPixelGameEngine.h>


class cWidget {
    olc::PixelGameEngine* gfx;

    olc::vi2d m_pos;
    olc::vi2d m_size;

public: 
    cWidget(olc::PixelGameEngine * gfx);

protected:
    virtual void onClick() {};
    virtual void onHover() {};

    olc::vf2d
}