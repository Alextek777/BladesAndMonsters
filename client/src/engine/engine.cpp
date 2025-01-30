
#include "engine.h"

#define X(n) m_script.AddCommand(new cCommand_ ## n)

Engine::Engine()
{
	sAppName = "Top Down Role Playing Game";
}



bool Engine::OnUserCreate()
{
	Assets::get().LoadSprites();
	Assets::get().LoadMaps(this);
    Assets::get().LoadAnimations();

    m_pPlayer = new cDynamic_Creature_Witty();
    m_vecDynamics.push_back(m_pPlayer);

	ChangeMap("village", 0, 0);
    
    return true;
}

bool Engine::OnUserUpdate(float fElapsedTime)
{
	switch (m_nGameMode)
	{
	case MODE_LOCAL_MAP:
		return UpdateLocalMap(fElapsedTime);
	}

    return true;
}

bool Engine::UpdateLocalMap(float fElapsedTime)
{   
    Clear(olc::BLANK);

    //----------------------------------------- player -------------------------------------------
    // TODO: incapsulate all user input in handler func

    fCameraPosX = m_pPlayer->px - ScreenWidth() / 2;
    fCameraPosY = m_pPlayer->py - ScreenHeight() / 2;

    m_pCurrentMap->DrawStaticMap(fCameraPosX, fCameraPosY);

    m_pPlayer->vx = 0;
    m_pPlayer->vy = 0;
    if (GetKey(olc::UP).bHeld)
        m_pPlayer->vy = -40.0f;

    if (GetKey(olc::DOWN).bHeld)
        m_pPlayer->vy = 40.0f;

    if (GetKey(olc::LEFT).bHeld)
        m_pPlayer->vx = -40.0f;

    if (GetKey(olc::RIGHT).bHeld)
        m_pPlayer->vx = 40.0f;

    //----------------------------------------- player END -------------------------------------------
    
    std::sort(m_vecDynamics.begin(), m_vecDynamics.end(), [](const cDynamic* a, const cDynamic* b) {
        return a->py < b->py;
    });

    SetPixelMode(olc::Pixel::ALPHA);

    for (auto dynamic : m_vecDynamics) {
        dynamic->Update(fElapsedTime, m_pPlayer);
	    dynamic->DrawSelf(this, fCameraPosX, fCameraPosY);
    }

    SetPixelMode(olc::Pixel::NORMAL);

    return true;
}

void Engine::ChangeMap(string sMapName, float x, float y)
{
	// Destroy all dynamics
	// m_vecDynamics.clear();
	// m_vecDynamics.push_back(m_pPlayer);

	// Set current map
	m_pCurrentMap = Assets::get().GetMap(sMapName);

	// Update player location
	m_pPlayer->px = x;
	m_pPlayer->py = y;

	// Create new dynamics from map
	m_pCurrentMap->PopulateDynamics(m_vecDynamics);

	// // Create new dynamics from quests
	// for (auto q : m_listQuests)
	// 	q->PopulateDynamics(m_vecDynamics, m_pCurrentMap->sName);
}