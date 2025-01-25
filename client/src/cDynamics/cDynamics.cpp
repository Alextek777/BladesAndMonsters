#include "cDynamics.h"
#include "engine/engine.h"


Engine* cDynamic::g_engine = nullptr;

cDynamic::cDynamic(string n)
{
	sName = n;
	px = 0.0f;
	py = 0.0f;
	vx = 0.0f;
	vy = 0.0f;
	bSolidVsMap = true;
	bSolidVsDyn = true;
	bFriendly = true;
	bRedundant = false;
	bIsAttackable = false;
	bIsProjectile = false;
}

cDynamic::~cDynamic()
{

}


/////////////////////////////////////////////////////////////////////


cDynamic_Creature::cDynamic_Creature(string name, olc::Sprite *sprite) : cDynamic(name)
{
	m_pSprite = sprite;
	nHealth = 10;
	nHealthMax = 10;
	m_nFacingDirection = SOUTH;
	m_nGraphicState = STANDING;
	m_nGraphicCounter = 0;
	m_fTimer = 0.0f;
	bIsAttackable = true;
}

void cDynamic_Creature::Update(float fElapsedTime, cDynamic* player)
{
	if (m_fKnockBackTimer > 0.0f)
	{
		vx = m_fKnockBackDX * 10.0f;
		vy = m_fKnockBackDY * 10.0f;
		bIsAttackable = false;
		m_fKnockBackTimer -= fElapsedTime;
		if (m_fKnockBackTimer <= 0.0f)
		{
			m_fStateTick = 0.0f;
			bControllable = true;
			bIsAttackable = true;
		}

	}
	else
	{
		bSolidVsDyn = true;
		m_fTimer += fElapsedTime;
		if (m_fTimer >= 0.2f)
		{
			m_fTimer -= 0.2f;
			m_nGraphicCounter++;
			m_nGraphicCounter %= 2;
		}

		if (fabs(vx) > 0 || fabs(vy) > 0)
			m_nGraphicState = WALKING;
		else
			m_nGraphicState = STANDING;

		if (nHealth <= 0)
			m_nGraphicState = DEAD;

		if (vx < 0.0f) m_nFacingDirection = WEST;
		if (vx > 0.0f) m_nFacingDirection = EAST;
		if (vy < -0.0f) m_nFacingDirection = NORTH;
		if (vy > 0.0f) m_nFacingDirection = SOUTH;

		Behaviour(fElapsedTime, player);
	}
}

void cDynamic_Creature::KnockBack(float dx, float dy, float dist)
{
	m_fKnockBackDX = dx;
	m_fKnockBackDY = dy;
	m_fKnockBackTimer = dist;
	bSolidVsDyn = false;
	bControllable = false;
	bIsAttackable = false;
}


void cDynamic_Creature::DrawSelf(olc::PixelGameEngine *gfx, float ox, float oy)
{
	int nSheetOffsetX = 0;
	int nSheetOffsetY = 0;

	switch (m_nGraphicState)
	{
	case STANDING:
		nSheetOffsetX = m_nFacingDirection * 16;
		break;

	case WALKING:
		nSheetOffsetX = m_nFacingDirection * 16;
		nSheetOffsetY = m_nGraphicCounter * 16;
		break;

	case CELEBRATING:
		nSheetOffsetX = 4 * 16;
		break;

	case DEAD:
		nSheetOffsetX = 4 * 16;
		nSheetOffsetY = 1 * 16;
		break;

	}

	gfx->DrawPartialSprite((px - ox) * 16.0f, (py - oy)*16.0f, m_pSprite, nSheetOffsetX, nSheetOffsetY, 16, 16);
}

void cDynamic_Creature::Behaviour(float fElapsedTime, cDynamic* player)
{
	player->px += player->vx * fElapsedTime;
	player->py += player->vy * fElapsedTime;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


cDynamic_Creature_Witty::cDynamic_Creature_Witty() : cDynamic_Creature("witty", Assets::get().GetSprite("player"))
{
	bFriendly = true;
	nHealth = 9;
	nHealthMax = 10;
	m_fStateTick = 2.0f;
	// pEquipedWeapon = (cWeapon*)Assets::get().GetItem("Basic Sword");
}

void cDynamic_Creature_Witty::PerformAttack()
{
	// if (pEquipedWeapon == nullptr)
	// 	return;

	// pEquipedWeapon->OnUse(this);
}