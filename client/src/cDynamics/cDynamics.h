#pragma once 
#include "cMaps/cAssets.h"
#include <olcPixelGameEngine.h>
#include "consts/consts.h"

class Engine;
// class cItem;
// class cWeapon;

using namespace std;

class cDynamic
{
public:
	cDynamic(string n);
	~cDynamic();

public:
	float px, py;
	float vx, vy;
	bool bSolidVsMap;
	bool bSolidVsDyn;
	bool bFriendly;
	bool bRedundant;
	bool bIsProjectile;
	bool bIsAttackable;
	string sName;

protected:
	int m_nGraphicCounter;
	float m_fTimer;

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

protected:
	e_FactionDirection m_nFacingDirection;
	e_GraphicsState m_nGraphicState;

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


class cDynamic_Creature_Witty : public cDynamic_Creature
{
public:
	cDynamic_Creature_Witty();

public:
	void PerformAttack() override;
};


class cDynamic_Object : public cDynamic 
{
public:
	cDynamic_Object(string, float, float);

	void DrawSelf(olc::PixelGameEngine *gfx, float ox, float oy) override;
	void Update(float fElapsedTime, cDynamic* player = nullptr) override;
};
