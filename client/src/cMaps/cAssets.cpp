
#include "cAssets.h"

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

	load("village", "rpgdata/gfx/tiles002.png");
}

void Assets::LoadMaps()
{
	
}
