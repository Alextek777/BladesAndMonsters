
#include "cAssets.h"
#include "cMaps/maps/cMapVillage.h"

Assets::Assets()
{
}


Assets::~Assets()
{
}

void Assets::LoadAnimations() {
	m_animationHandler.load("witty", e_GraphicsState::WALKING, e_FactionDirection::EAST, 8, 100, "animations/creatures/witty/walking/east.png");
	m_animationHandler.load("witty", e_GraphicsState::WALKING, e_FactionDirection::WEST, 8, 100, "animations/creatures/witty/walking/west.png");
	m_animationHandler.load("witty", e_GraphicsState::WALKING, e_FactionDirection::NORTH, 8, 100, "animations/creatures/witty/walking/east.png");
	m_animationHandler.load("witty", e_GraphicsState::WALKING, e_FactionDirection::SOUTH, 8, 100, "animations/creatures/witty/walking/west.png");

	m_animationHandler.load("witty", e_GraphicsState::STANDING, e_FactionDirection::EAST, 6, 100, "animations/creatures/witty/standing/east.png");
	m_animationHandler.load("witty", e_GraphicsState::STANDING, e_FactionDirection::WEST, 6, 100, "animations/creatures/witty/standing/west.png");
	m_animationHandler.load("witty", e_GraphicsState::STANDING, e_FactionDirection::NORTH, 6, 100, "animations/creatures/witty/standing/east.png");
	m_animationHandler.load("witty", e_GraphicsState::STANDING, e_FactionDirection::SOUTH, 6, 100, "animations/creatures/witty/standing/west.png");

	m_animationHandler.load("witty", e_GraphicsState::ATTACKING, e_FactionDirection::EAST, 6, 100, "animations/creatures/witty/attacking/east.png");
	m_animationHandler.load("witty", e_GraphicsState::ATTACKING, e_FactionDirection::WEST, 6, 100, "animations/creatures/witty/attacking/west.png");
	m_animationHandler.load("witty", e_GraphicsState::ATTACKING, e_FactionDirection::NORTH, 6, 100, "animations/creatures/witty/attacking/east.png");
	m_animationHandler.load("witty", e_GraphicsState::ATTACKING, e_FactionDirection::SOUTH, 6, 100, "animations/creatures/witty/attacking/west.png");


	m_animationHandler.load("orc", e_GraphicsState::WALKING, e_FactionDirection::EAST, 8, 100, "animations/creatures/orc/walking/east.png");
	m_animationHandler.load("orc", e_GraphicsState::WALKING, e_FactionDirection::WEST, 8, 100, "animations/creatures/orc/walking/west.png");
	m_animationHandler.load("orc", e_GraphicsState::WALKING, e_FactionDirection::NORTH, 8, 100, "animations/creatures/orc/walking/east.png");
	m_animationHandler.load("orc", e_GraphicsState::WALKING, e_FactionDirection::SOUTH, 8, 100, "animations/creatures/orc/walking/west.png");

	m_animationHandler.load("orc", e_GraphicsState::STANDING, e_FactionDirection::EAST, 6, 100, "animations/creatures/orc/standing/east.png");
	m_animationHandler.load("orc", e_GraphicsState::STANDING, e_FactionDirection::WEST, 6, 100, "animations/creatures/orc/standing/west.png");
	m_animationHandler.load("orc", e_GraphicsState::STANDING, e_FactionDirection::NORTH, 6, 100, "animations/creatures/orc/standing/east.png");
	m_animationHandler.load("orc", e_GraphicsState::STANDING, e_FactionDirection::SOUTH, 6, 100, "animations/creatures/orc/standing/west.png");

	m_animationHandler.load("orc", e_GraphicsState::ATTACKING, e_FactionDirection::EAST, 6, 100, "animations/creatures/orc/attacking/east.png");
	m_animationHandler.load("orc", e_GraphicsState::ATTACKING, e_FactionDirection::WEST, 6, 100, "animations/creatures/orc/attacking/west.png");
	m_animationHandler.load("orc", e_GraphicsState::ATTACKING, e_FactionDirection::NORTH, 6, 100, "animations/creatures/orc/attacking/east.png");
	m_animationHandler.load("orc", e_GraphicsState::ATTACKING, e_FactionDirection::SOUTH, 6, 100, "animations/creatures/orc/attacking/west.png");


	m_animationHandler.load("TreeAutumn", e_GraphicsState::DEFAULT_GS, e_FactionDirection::DEFAULT_FD, 16, 64, "animations/trees/autumn/default.png");
}

void Assets::LoadSprites()
{
	auto load = [&](std::string sName, std::string sFileName)
	{
		olc::Sprite* s = new olc::Sprite(sFileName);
		m_mapSprites[sName] = s;
		m_mapDecal[sName] = new olc::Decal(s);
	};

	load("village", "sprites/isometric_demo.png");
}

void Assets::LoadMaps(olc::PixelGameEngine* gfx)
{
    auto load = [&](cMap* m)
	{
		m_mapMaps[m->sName] = m;
	};

	load(new cMap_Village(gfx));
}
