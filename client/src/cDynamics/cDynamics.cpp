#include "cDynamics.h"
#include "engine/engine.h"


extern e_GameMode GAMEMODE; 
Engine* cDynamic::g_engine = nullptr;

cDynamic::cDynamic(string n, float ox, float oy)
{
	sName = n;
	px = ox;
	py = oy;
	vx = 0.0f;
	vy = 0.0f;
	size = olc::vi2d(10,10);
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


cDynamic_Creature::cDynamic_Creature(string name) : cDynamic(name, 0, 0)
{
	nHealth = 10;
	nHealthMax = 10;
	m_nFacingDirection = SOUTH;
	m_nGraphicState = STANDING;
	m_nGraphicCounter = 0;
	m_fTimer = 0.0f;
	bIsAttackable = true;
	size = olc::vi2d(100, 100);
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
		if (m_fTimer >= 0.1f)
		{
			m_fTimer = 0;
			m_nGraphicCounter = (m_nGraphicCounter + 1) % 16;
		}

		if (fabs(vx) > 1 || fabs(vy) > 1)
			m_nGraphicState = WALKING;
		else {
			// if performing attack wait till it ends
			if (m_nGraphicState != ATTACKING || m_nGraphicCounter == 0) {
				m_nGraphicState = STANDING;		
			}	
		}


		if (nHealth <= 0)
			m_nGraphicState = DEAD;

		if (vx < 0.0f) m_nFacingDirection = WEST;
		if (vx > 0.0f) m_nFacingDirection = EAST;
		if (vy < -0.0f) m_nFacingDirection = NORTH;
		if (vy > 0.0f) m_nFacingDirection = SOUTH;

		player->px += player->vx * fElapsedTime;
		player->py += player->vy * fElapsedTime;

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
	AnimationFrame* frame;
	try
	{
		frame = Assets::get().GetAnimationFrame(sName, m_nGraphicState, m_nFacingDirection, m_nGraphicCounter);
	}
	catch(const std::exception& e)
	{
		std::cerr << "can not load animation frame for dynamic object:" << sName << " error: " << e.what() << '\n';
		return;
	}

	olc::vf2d pos((px - ox), (py - oy));
	olc::vf2d source_Pos(frame->ox, frame->oy);
	olc::vf2d source_Size(frame->width, frame->height);
	gfx->DrawPartialDecal(pos, frame->decal, source_Pos, source_Size);

	if (GAMEMODE == DEBUG) {
		gfx->DrawRect(pos, size, olc::WHITE);
	} 
}

void cDynamic_Creature::Behaviour(float fElapsedTime, cDynamic* player)
{
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


cDynamic_Object::cDynamic_Object(string name, float px, float py) : cDynamic(name, px, py) {
	m_nGraphicCounter = rand() % 5;
	bIsAttackable = false;

	size = olc::vi2d(64,64);
}

void cDynamic_Object::DrawSelf(olc::PixelGameEngine *gfx, float ox, float oy) {
	AnimationFrame* frame;
	try
	{
		frame = Assets::get().GetAnimationFrame(sName, m_nGraphicCounter);
	}
	catch(const std::exception& e)
	{
		std::cerr << "can not load animation frame for dynamic object:" << sName << " error: " << e.what() << '\n';
		return;
	}

	olc::vf2d pos((px - ox), (py - oy));
	olc::vf2d source_Pos(frame->ox, frame->oy);
	olc::vf2d source_Size(frame->width, frame->height);
	gfx->DrawPartialDecal(pos, frame->decal, source_Pos, source_Size);

	if (GAMEMODE == DEBUG) {
		gfx->DrawRect(pos, size, olc::WHITE);
	} 
}

void cDynamic_Object::Update(float fElapsedTime, cDynamic* player) {
	m_fTimer += fElapsedTime;
	if (m_fTimer >= 0.12f)
	{
		m_fTimer = 0;
		m_nGraphicCounter = (m_nGraphicCounter + 1) % 16;
	}
}