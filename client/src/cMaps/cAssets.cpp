
#include "cAssets.h"
#include "cMapVillage.h"

Assets::Assets()
{
}


Assets::~Assets()
{
}

void Assets::LoadSprites()
{
	auto load = [&](std::string sName, std::string sFileName)
	{
		olc::Sprite* s = new olc::Sprite(sFileName);
		m_mapSprites[sName] = s;
	};

	load("village", "sprites/isometric_demo.png");
	load("player", "sprites/player.png");
}

void Assets::LoadMaps()
{
    auto load = [&](cMap* m)
	{
		m_mapMaps[m->sName] = m;
	};

	load(new cMap_Village());
}
