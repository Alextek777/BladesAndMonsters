
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

	ChangeMap("village", 5, 5);
    
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
    Clear(olc::WHITE);

    // Get Mouse in world
    olc::vi2d vMouse = { GetMouseX(), GetMouseY() };
    
    // Work out active cell
    olc::vi2d vCell = { vMouse.x / m_pCurrentMap->vTileSize.x, vMouse.y / m_pCurrentMap->vTileSize.y };

    // Work out mouse offset into cell
    olc::vi2d vOffset = { vMouse.x % m_pCurrentMap->vTileSize.x, vMouse.y % m_pCurrentMap->vTileSize.y };

    // Sample into cell offset colour
    olc::Pixel col = Assets::get().GetSprite(m_pCurrentMap->sName)->GetPixel(3 * m_pCurrentMap->vTileSize.x + vOffset.x, vOffset.y);

    // Work out selected cell by transforming screen cell
    olc::vi2d vSelected = 
    {
        (vCell.y - m_pCurrentMap->vOrigin.y) + (vCell.x - m_pCurrentMap->vOrigin.x),
        (vCell.y - m_pCurrentMap->vOrigin.y) - (vCell.x - m_pCurrentMap->vOrigin.x) 
    };

    // "Bodge" selected cell by sampling corners
    if (col == olc::RED) vSelected += {-1, +0};
    if (col == olc::BLUE) vSelected += {+0, -1};
    if (col == olc::GREEN) vSelected += {+0, +1};
    if (col == olc::YELLOW) vSelected += {+1, +0};
                    
    // Labmda function to convert "world" coordinate into screen space
    auto ToScreen = [&](int x, int y)
    {			
        return olc::vi2d
        {
            (m_pCurrentMap->vOrigin.x * m_pCurrentMap->vTileSize.x) + (x - y) * (m_pCurrentMap->vTileSize.x / 2),
            (m_pCurrentMap->vOrigin.y * m_pCurrentMap->vTileSize.y) + (x + y) * (m_pCurrentMap->vTileSize.y / 2)
        };
    };
    
    // Draw World - has binary transparancy so enable masking
    SetPixelMode(olc::Pixel::MASK);

    // (0,0) is at top, defined by m_pCurrentMap->vOrigin, so draw from top to bottom
    // to ensure tiles closest to camera are drawn last
    for (int y = 0; y < m_pCurrentMap->nHeight; y++)
    {
        for (int x = 0; x < m_pCurrentMap->nWidth; x++)
        {
            // Convert cell coordinate to world space
            olc::vi2d vWorld = ToScreen(x, y);
            
            switch(m_pCurrentMap->GetIndex(x, y))
            {
            case 0:
                // Invisble Tile
                DrawPartialSprite(vWorld.x, vWorld.y, Assets::get().GetSprite(m_pCurrentMap->sName), 1 * m_pCurrentMap->vTileSize.x, 0, m_pCurrentMap->vTileSize.x, m_pCurrentMap->vTileSize.y);
                break;
            case 1:
                // Visible Tile
                DrawPartialSprite(vWorld.x, vWorld.y, Assets::get().GetSprite(m_pCurrentMap->sName), 2 * m_pCurrentMap->vTileSize.x, 0, m_pCurrentMap->vTileSize.x, m_pCurrentMap->vTileSize.y);
                break;
            case 2:
                // Tree
                DrawPartialSprite(vWorld.x, vWorld.y - m_pCurrentMap->vTileSize.y, Assets::get().GetSprite(m_pCurrentMap->sName), 0 * m_pCurrentMap->vTileSize.x, 1 * m_pCurrentMap->vTileSize.y, m_pCurrentMap->vTileSize.x, m_pCurrentMap->vTileSize.y * 2);
                break;
            case 3:
                // Spooky Tree
                DrawPartialSprite(vWorld.x, vWorld.y - m_pCurrentMap->vTileSize.y, Assets::get().GetSprite(m_pCurrentMap->sName), 1 * m_pCurrentMap->vTileSize.x, 1 * m_pCurrentMap->vTileSize.y, m_pCurrentMap->vTileSize.x, m_pCurrentMap->vTileSize.y * 2);
                break;
            case 4:
                // Beach
                DrawPartialSprite(vWorld.x, vWorld.y - m_pCurrentMap->vTileSize.y, Assets::get().GetSprite(m_pCurrentMap->sName), 2 * m_pCurrentMap->vTileSize.x, 1 * m_pCurrentMap->vTileSize.y, m_pCurrentMap->vTileSize.x, m_pCurrentMap->vTileSize.y * 2);
                break;
            case 5:
                // Water
                DrawPartialSprite(vWorld.x, vWorld.y - m_pCurrentMap->vTileSize.y, Assets::get().GetSprite(m_pCurrentMap->sName), 3 * m_pCurrentMap->vTileSize.x, 1 * m_pCurrentMap->vTileSize.y, m_pCurrentMap->vTileSize.x, m_pCurrentMap->vTileSize.y * 2);
                break;
            }			
        }
    }

    // Draw Selected Cell - Has varying alpha components
    SetPixelMode(olc::Pixel::ALPHA);

    // Convert selected cell coordinate to world space
    olc::vi2d vSelectedWorld = ToScreen(vSelected.x, vSelected.y);

    // Draw "highlight" tile
    DrawPartialSprite(vSelectedWorld.x, vSelectedWorld.y, Assets::get().GetSprite(m_pCurrentMap->sName), 0 * m_pCurrentMap->vTileSize.x, 0, m_pCurrentMap->vTileSize.x, m_pCurrentMap->vTileSize.y);

    // Go back to normal drawing with no expected transparency
    SetPixelMode(olc::Pixel::NORMAL);

    // Draw Hovered Cell Boundary
    //DrawRect(vCell.x * m_pCurrentMap->vTileSize.x, vCell.y * m_pCurrentMap->vTileSize.y, m_pCurrentMap->vTileSize.x, m_pCurrentMap->vTileSize.y, olc::RED);
            
    // Draw Debug Info
    DrawString(4, 4, "Mouse   : " + std::to_string(vMouse.x) + ", " + std::to_string(vMouse.y), olc::BLACK);
    DrawString(4, 14, "Cell    : " + std::to_string(vCell.x) + ", " + std::to_string(vCell.y), olc::BLACK);
    DrawString(4, 24, "Selected: " + std::to_string(vSelected.x) + ", " + std::to_string(vSelected.y), olc::BLACK);




    //----------------------------------------- player -------------------------------------------
    m_pPlayer->vx = 0;
    m_pPlayer->vy = 0;
    if (GetKey(olc::UP).bHeld)
        m_pPlayer->vy = -7.0f;

    if (GetKey(olc::DOWN).bHeld)
        m_pPlayer->vy = 7.0f;

    if (GetKey(olc::LEFT).bHeld)
        m_pPlayer->vx = -7.0f;

    if (GetKey(olc::RIGHT).bHeld)
        m_pPlayer->vx = 7.0f;
        

	// fCameraPosX = m_pPlayer->px;
	// fCameraPosY = m_pPlayer->py;

	// float fOffsetX = fCameraPosX - (float)nVisibleTilesX / 2.0f;
	// float fOffsetY = fCameraPosY - (float)nVisibleTilesY / 2.0f;
    m_pPlayer->Update(fElapsedTime, m_pPlayer);
	m_pPlayer->DrawSelf(this, 0, 0);


    //----------------------------------------- player END -------------------------------------------


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
	// m_pPlayer->px = x;
	// m_pPlayer->py = y;

	// Create new dynamics from map
	// m_pCurrentMap->PopulateDynamics(m_vecDynamics);

	// // Create new dynamics from quests
	// for (auto q : m_listQuests)
	// 	q->PopulateDynamics(m_vecDynamics, m_pCurrentMap->sName);
}