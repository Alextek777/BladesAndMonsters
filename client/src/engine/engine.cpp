
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

	ChangeMap("village", 200, 200);
    
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

    UpdateStaticMap(fElapsedTime);
    HandleUserInput(fElapsedTime);
    
    
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


void Engine::UpdateStaticMap(float fElapsedTime) {
    olc::vi2d mouse = GetMousePos();
    bool updateMap = false;

    if (mouse.x < 10 ) {
        fCameraPosX -= 100 * fElapsedTime;
        updateMap = true;
    }
    
    if ( mouse.x > ScreenWidth() - 10) {
        fCameraPosX += 100 * fElapsedTime;
        updateMap = true;
    }
    
    if (mouse.y < 10 ) {
        fCameraPosY -= 100 * fElapsedTime;
        updateMap = true;
    }
    
    if (mouse.y > ScreenHeight() - 10 ) {
        fCameraPosY += 100 * fElapsedTime;
        updateMap = true;
    }

    if (updateMap) {
        m_pCurrentMap->DrawStaticMap(fCameraPosX, fCameraPosY);
    }
}

void Engine::HandleUserInput(float fElapsedTime) {
    m_pPlayer->vx = 0;
    m_pPlayer->vy = 0;

    // Walk 
    if (GetKey(olc::UP).bHeld) 
        m_pPlayer->vy = -40.0f;

    if (GetKey(olc::DOWN).bHeld)
        m_pPlayer->vy = 40.0f;

    if (GetKey(olc::LEFT).bHeld)
        m_pPlayer->vx = -40.0f;

    if (GetKey(olc::RIGHT).bHeld)
        m_pPlayer->vx = 40.0f;


    // Atack
    if (GetKey(olc::SPACE).bPressed) 
        m_pPlayer->PerformAttack();

}