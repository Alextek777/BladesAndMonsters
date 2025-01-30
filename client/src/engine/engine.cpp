
#include "engine.h"

#define X(n) m_script.AddCommand(new cCommand_ ## n)

Engine::Engine()
{
	sAppName = "Top Down Role Playing Game";
}



bool Engine::OnUserCreate()
{
	Assets::get().LoadSprites();
	Assets::get().LoadMaps();
    Assets::get().LoadAnimations();

    m_pPlayer = new cDynamic_Creature_Witty();
    m_vecDynamics.push_back(m_pPlayer);

	ChangeMap("village", 10, 10);

    m_pCurrentMap->DrawStaticMap(this);
    
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

    // // Get Mouse in world
    // olc::vi2d vMouse = { GetMouseX(), GetMouseY() };
    
    // // Work out active cell
    // olc::vi2d vCell = { vMouse.x / m_pCurrentMap->vTileSize.x, vMouse.y / m_pCurrentMap->vTileSize.y };

    // // Work out mouse offset into cell
    // olc::vi2d vOffset = { vMouse.x % m_pCurrentMap->vTileSize.x, vMouse.y % m_pCurrentMap->vTileSize.y };

    // // Sample into cell offset colour
    // olc::Pixel col = Assets::get().GetSprite(m_pCurrentMap->sName)->GetPixel(3 * m_pCurrentMap->vTileSize.x + vOffset.x, vOffset.y);

    // // Work out selected cell by transforming screen cell
    // olc::vi2d vSelected = 
    // {
    //     (vCell.y - m_pCurrentMap->vOrigin.y) + (vCell.x - m_pCurrentMap->vOrigin.x),
    //     (vCell.y - m_pCurrentMap->vOrigin.y) - (vCell.x - m_pCurrentMap->vOrigin.x) 
    // };

    // // "Bodge" selected cell by sampling corners
    // if (col == olc::RED) vSelected += {-1, +0};
    // if (col == olc::BLUE) vSelected += {+0, -1};
    // if (col == olc::GREEN) vSelected += {+0, +1};
    // if (col == olc::YELLOW) vSelected += {+1, +0};

    //----------------------------------------- player -------------------------------------------
    // TODO: incapsulate all user input in handler func

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


    // Draw World - has binary transparancy so enable masking
    SetPixelMode(olc::Pixel::ALPHA);
    
    std::sort(m_vecDynamics.begin(), m_vecDynamics.end(), [](const cDynamic* a, const cDynamic* b) {
        return a->py < b->py;
    });

    for (auto dynamic : m_vecDynamics) {
        dynamic->Update(fElapsedTime, m_pPlayer);
	    dynamic->DrawSelf(this, 0, 0);
    }

    // Go back to normal drawing with no expected transparency
    SetPixelMode(olc::Pixel::NORMAL);

    // // Convert selected cell coordinate to world space
    // olc::vi2d vSelectedWorld = ToScreen(vSelected.x, vSelected.y);

    // // Draw "highlight" tile
    // DrawPartialSprite(vSelectedWorld.x, vSelectedWorld.y, Assets::get().GetSprite(m_pCurrentMap->sName), 0 * m_pCurrentMap->vTileSize.x, 0, m_pCurrentMap->vTileSize.x, m_pCurrentMap->vTileSize.y);



    // // Draw Hovered Cell Boundary
    // //DrawRect(vCell.x * m_pCurrentMap->vTileSize.x, vCell.y * m_pCurrentMap->vTileSize.y, m_pCurrentMap->vTileSize.x, m_pCurrentMap->vTileSize.y, olc::RED);
            
    // // Draw Debug Info
    // DrawString(4, 4, "Mouse   : " + std::to_string(vMouse.x) + ", " + std::to_string(vMouse.y), olc::BLACK);
    // DrawString(4, 14, "Cell    : " + std::to_string(vCell.x) + ", " + std::to_string(vCell.y), olc::BLACK);
    // DrawString(4, 24, "Selected: " + std::to_string(vSelected.x) + ", " + std::to_string(vSelected.y), olc::BLACK);

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