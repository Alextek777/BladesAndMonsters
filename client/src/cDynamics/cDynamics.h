#pragma once 

#include "cAssets/cAssets.h"

class Engine;
class AnimationFrame;

using namespace std;

class cDynamic
{
public:
	cDynamic(string name, float ox, float oy);
	~cDynamic();

public:
	float px, py;
	float vx, vy;

	olc::vi2d size;

	bool bSolidVsMap;
	bool bSolidVsDyn;
	bool bFriendly;
	bool bRedundant;
	bool bIsProjectile;
	bool bIsAttackable;
	string sName;

protected:
	e_FactionDirection m_nFacingDirection;
	e_GraphicsState m_nGraphicState;
	uint16_t animetionFrameCount = 0;
	AnimationFrame* frame;

	int m_nGraphicCounter;
	float m_fTimerLimit;
	float m_fTimer;

	bool loadFrame();

public:
	virtual void DrawSelf(olc::PixelGameEngine *gfx, float ox, float oy) {}
	virtual void Update(float fElapsedTime, cDynamic* player = nullptr) {}
	virtual void OnInteract(cDynamic* player = nullptr) {}

	static Engine* g_engine;
};



class cDynamic_Creature : public cDynamic
{
public:
	cDynamic_Creature(string n);

public:
	int nHealth;
	int nHealthMax;
	int bControllable = true;

public:
	void DrawSelf(olc::PixelGameEngine *gfx, float ox, float oy) override;
	void Update(float fElapsedTime, cDynamic* player = nullptr) override;
	virtual void Behaviour(float fElapsedTime, cDynamic* player = nullptr);
	int GetFacingDirection() { return m_nFacingDirection; };
	virtual void PerformAttack() {};
	void KnockBack(float dx, float dy, float dist);

	// cWeapon *pEquipedWeapon = nullptr;

protected:
	float m_fStateTick;
	float m_fKnockBackTimer = 0.0f;
	float m_fKnockBackDX = 0.0f;
	float m_fKnockBackDY = 0.0f;
	

};


class cDynamic_Object : public cDynamic 
{
public:
	cDynamic_Object(string, float, float);

	void DrawSelf(olc::PixelGameEngine *gfx, float ox, float oy) override;
	void Update(float fElapsedTime, cDynamic* player = nullptr) override;
};
