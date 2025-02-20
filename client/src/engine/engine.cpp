
#include "engine.h"

#define X(n) m_script.AddCommand(new cCommand_##n)

Engine::Engine()
{
    sAppName = "Blades And Monsters";
}

bool Engine::OnUserCreate()
{
    Assets::get().LoadSprites();
    Assets::get().LoadMaps(this);
    Assets::get().LoadAnimations();


    m_pInventory   =  new cInventory(this);
    m_pDefaultMenu = new cDefaultMenu(this);

    m_pPlayer = new cDynamic_Creature_Witty();

    ChangeMap("village", 200, 300);
    UpdateStaticMap(0);

    return true;
}

bool Engine::OnUserUpdate(float fElapsedTime)
{

    HandleUserInput(fElapsedTime);

    // switch (m_nGameMode)
    // {
    // case MODE_LOCAL_MAP:
    //     return UpdateLocalMap(fElapsedTime);
    // default:
    //     return UpdateMenu(fElapsedTime);
    // }

    UpdateLocalMap(fElapsedTime);
    UpdateMenu(fElapsedTime);

    return true;
}

bool Engine::UpdateLocalMap(float fElapsedTime)
{
    Clear(olc::BLANK);

    UpdateStaticMap(fElapsedTime);

    std::sort(m_vecDynamics.begin(), m_vecDynamics.end(), [](const cDynamic *a, const cDynamic *b)
              { return (a->py + a->size.y) < (b->py + b->size.y); });


    for (auto dynamic : m_vecDynamics)
    {
        // Check static map collision
        if (m_pCurrentMap->Collides(dynamic, fElapsedTime)) {
            dynamic->vx = 0;
            dynamic->vy = 0;
        }

        dynamic->Update(fElapsedTime, m_pPlayer);
        dynamic->DrawSelf(this, fCameraPosX, fCameraPosY);
    }


    return true;
}

bool Engine::UpdateMenu(float fElapsedTime) {
    if ( m_nGameMode == MODE_INVENTORY ) {
        m_pInventory->DrawSelf(fElapsedTime);
    }

    if ( m_nGameMode == MODE_MENU ) {
        m_pDefaultMenu->DrawSelf(fElapsedTime);
    }

    return true;
}

void Engine::ChangeMap(string sMapName, float x, float y)
{
    m_vecDynamics.clear();

    m_vecDynamics.push_back(m_pPlayer);
    m_pPlayer->px = x;
    m_pPlayer->py = y;

    m_pCurrentMap = Assets::get().GetMap(sMapName);

    m_pCurrentMap->PopulateDynamics(m_vecDynamics);

    // // Create new dynamics from quests
    // for (auto q : m_listQuests)
    // 	q->PopulateDynamics(m_vecDynamics, m_pCurrentMap->sName);
}

// Camera handle
void Engine::UpdateStaticMap(float fElapsedTime)
{
    olc::vi2d mouse = GetMousePos();
    bool updateMap = false;

    if (mouse.x < 10)
    {
        fCameraPosX -= 150 * fElapsedTime;
        updateMap = true;
    }

    if (mouse.x > ScreenWidth() - 10)
    {
        fCameraPosX += 150 * fElapsedTime;
        updateMap = true;
    }

    if (mouse.y < 10)
    {
        fCameraPosY -= 150 * fElapsedTime;
        updateMap = true;
    }

    if (mouse.y > ScreenHeight() - 10)
    {
        fCameraPosY += 150 * fElapsedTime;
        updateMap = true;
    }

    if (updateMap)
    {
        m_pCurrentMap->DrawStaticMap(fCameraPosX, fCameraPosY);
    }
}

void Engine::HandleUserInput(float fElapsedTime)
{
    m_pPlayer->vx = 0;
    m_pPlayer->vy = 0;

    // Atack
    if (GetKey(olc::SPACE).bPressed)
        m_pPlayer->PerformAttack();


    // Walk
    if (GetKey(olc::W).bHeld)
        m_pPlayer->vy = -30.0f;

    if (GetKey(olc::S).bHeld)
        m_pPlayer->vy = 30.0f;

    if (GetKey(olc::A).bHeld)
        m_pPlayer->vx = -30.0f;

    if (GetKey(olc::D).bHeld)
        m_pPlayer->vx = 30.0f;


    // Normalize Speed vector
    if (m_pPlayer->vx != 0 && m_pPlayer->vy != 0) {
        m_pPlayer->vx * 0.7071; // 1 / sqrt(2)
        m_pPlayer->vy * 0.7071; // 1 / sqrt(2)
    }

    // Open Inventory
    if (GetKey(olc::TAB).bPressed) 
        m_nGameMode = m_nGameMode == MODE_INVENTORY ? MODE_LOCAL_MAP : MODE_INVENTORY;

    // Open Default Menu
    if (GetKey(olc::ESCAPE).bPressed) 
        m_nGameMode = m_nGameMode == MODE_MENU ? MODE_LOCAL_MAP : MODE_MENU;
}