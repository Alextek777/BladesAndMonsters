#pragma once

#include <map>
#include "cAnimations/cAnimations.h"

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

	AnimationFrame* GetAnimationFrame(string &name, e_GraphicsState state, e_FactionDirection direction, uint16_t counter) {
		return m_animationHandler.getAnimationFrame(name, state, direction, counter);
	}

	AnimationFrame* GetAnimationFrame(string &name, uint16_t counter) {
		return m_animationHandler.getAnimationFrame(name, e_GraphicsState::DEFAULT_GS, e_FactionDirection::DEFAULT_FD, counter);
	}

	uint16_t GetFrameCount(string &name, e_GraphicsState state = e_GraphicsState::DEFAULT_GS, e_FactionDirection direction = e_FactionDirection::DEFAULT_FD) {
		return m_animationHandler.getFrameCount(name, state, direction);
	}

	void LoadAnimations();
	void LoadSprites();
private:
	Assets();
	~Assets();	

	std::map<int, olc::Decal*> m_mapDecal;
	std::map<int, olc::Sprite*> m_mapSprite;

	cAnimationHandler m_animationHandler;
};






