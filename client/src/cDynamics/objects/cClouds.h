#pragma once
#include "../cDynamics.h"

class cDynamic_cloud : public cDynamic_Object {
	int m_speed;
public:
    cDynamic_cloud(string, float, float);

	void DrawSelf(olc::PixelGameEngine *gfx, float ox, float oy) override;
	void Update(float fElapsedTime, cDynamic* player = nullptr) override;
};

cDynamic_cloud::cDynamic_cloud(string name, float px, float py) : cDynamic_Object(name, px, py) {
	m_nGraphicCounter = rand() % 5;
	m_speed = 5 + rand() % 10;

	bIsAttackable = false;

	size = olc::vi2d(40,40);
}

void cDynamic_cloud::DrawSelf(olc::PixelGameEngine *gfx, float ox, float oy) {
    AnimationFrame* frame;
	try
	{
		frame = Assets::get().GetAnimationFrame(sName, m_nGraphicCounter);
	}
	catch(const std::exception& e)
	{
		std::cerr << "can not load animation frame for dynamic object:" << sName << " error: " << e.what() << '\n';
		return;
	}

	olc::vf2d pos((px - ox), (py - oy));
	olc::vf2d source_Pos(frame->ox, frame->oy);
	olc::vf2d source_Size(frame->width, frame->height);
	gfx->DrawPartialDecal(pos, frame->decal, source_Pos, source_Size);
}


void cDynamic_cloud::Update(float fElapsedTime, cDynamic* player) {
	m_fTimer += fElapsedTime;
	if (m_fTimer >= 0.72f)
	{
		m_fTimer = 0;
		m_nGraphicCounter = (m_nGraphicCounter + 1) % 4;
	}
    px += m_speed * fElapsedTime;
}