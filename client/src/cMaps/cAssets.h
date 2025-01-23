#pragma once

#include <olcPixelGameEngine.h>
#include "cMap.h"
#include <map>

class cMap;

class Assets
{
public:
	static Assets& get()
	{
		static Assets me;
		return me;
	}

	Assets(Assets const&) = delete;
	void operator=(Assets const&) = delete;

	olc::Sprite* GetSprite(std::string name)
	{
		return m_mapSprites[name];
	}

	cMap* GetMap(std::string name)
	{
		return m_mapMaps[name];
	}

	void LoadSprites();
    void LoadMaps();
private:
	Assets();
	~Assets();	

	std::map<std::string, olc::Sprite*> m_mapSprites;
	std::map<std::string, cMap*> m_mapMaps;
};


