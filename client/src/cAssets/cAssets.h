#pragma once

#include <olcPixelGameEngine.h>
#include <map>

#include "cMaps/cMap.h"
#include "cAnimations/cAnimations.h"

class cMap;
class cAnimationHandler;

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

	olc::Decal* GetDecal(int idx)
	{
		return m_mapDecal[idx];
	}

	olc::Sprite* GetSprite(int idx)
	{
		return m_mapSprite[idx];
	}

	cMap* GetMap(std::string name)
	{
		return m_mapMaps[name];
	}

	AnimationFrame* GetAnimationFrame(string &name, e_GraphicsState state, e_FactionDirection direction, uint16_t counter) {
		return m_animationHandler.getAnimationFrame(name, state, direction, counter);
	}

	AnimationFrame* GetAnimationFrame(string &name, uint16_t counter) {
		return m_animationHandler.getAnimationFrame(name, e_GraphicsState::DEFAULT_GS, e_FactionDirection::DEFAULT_FD, counter);
	}

	void LoadAnimations();
	void LoadSprites();
    void LoadMaps(olc::PixelGameEngine* gfx);
private:
	Assets();
	~Assets();	

	std::map<int, olc::Decal*> m_mapDecal;
	std::map<int, olc::Sprite*> m_mapSprite;

	std::map<std::string, cMap*> m_mapMaps;
	cAnimationHandler m_animationHandler;
};






