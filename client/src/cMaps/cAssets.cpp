
#include "cAssets.h"
#include "cMapVillage.h"

Assets::Assets()
{
}


Assets::~Assets()
{
}

void Assets::LoadAnimations() {
	m_animationHandler.load("witty", e_GraphicsState::WALKING, e_FactionDirection::EAST, 8, 100, "animations/witty/walking/east.png");
	m_animationHandler.load("witty", e_GraphicsState::WALKING, e_FactionDirection::WEST, 9, 100, "animations/witty/walking/west.png");
	m_animationHandler.load("witty", e_GraphicsState::WALKING, e_FactionDirection::NORTH, 8, 100, "animations/witty/walking/east.png");
	m_animationHandler.load("witty", e_GraphicsState::WALKING, e_FactionDirection::SOUTH, 8, 100, "animations/witty/walking/east.png");

	m_animationHandler.load("witty", e_GraphicsState::STANDING, e_FactionDirection::EAST, 6, 100, "animations/witty/standing/east.png");
	m_animationHandler.load("witty", e_GraphicsState::STANDING, e_FactionDirection::WEST, 6, 100, "animations/witty/standing/east.png");
	m_animationHandler.load("witty", e_GraphicsState::STANDING, e_FactionDirection::NORTH, 6, 100, "animations/witty/standing/east.png");
	m_animationHandler.load("witty", e_GraphicsState::STANDING, e_FactionDirection::SOUTH, 6, 100, "animations/witty/standing/east.png");


	m_animationHandler.load("TreeAutumn", e_GraphicsState::DEFAULT_GS, e_FactionDirection::DEFAULT_FD, 16, 64, "animations/trees/autumn/default.png");
}

void Assets::LoadSprites()
{
	auto load = [&](std::string sName, std::string sFileName)
	{
		olc::Sprite* s = new olc::Sprite(sFileName);
		m_mapSprites[sName] = s;
	};

	load("village", "sprites/isometric_demo.png");
}

void Assets::LoadMaps()
{
    auto load = [&](cMap* m)
	{
		m_mapMaps[m->sName] = m;
	};

	load(new cMap_Village());
}
