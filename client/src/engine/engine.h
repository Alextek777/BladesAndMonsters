#pragma once


#include "cMaps/cMap.h"
#include "cDynamics/creatures/witty.h"
#include "cMenu/cInventory/cInventory.h"
#include "cMenu/cDefaultMenu/cDefaultMenu.h"

#include "soloud.h"
#include "soloud_wav.h"


using namespace std;

class Engine : public olc::PixelGameEngine
{
public:
	Engine();

private:
	SoLoud::Soloud soloud;
	SoLoud::Wav sample;

	cMap *m_pCurrentMap = nullptr;

	cDynamic_Creature *m_pPlayer = nullptr;

	vector<cDynamic*> m_vecDynamics;    // Fixed
	vector<cDynamic*> m_vecProjectiles; // Transient

	float fCameraPosX = 0.0f;
	float fCameraPosY = 0.0f;


	cInventory   *m_pInventory;
	cDefaultMenu *m_pDefaultMenu;

	enum
	{
		MODE_TITLE,
		MODE_LOCAL_MAP,
		MODE_WORLD_MAP,
		MODE_INVENTORY,
		MODE_MENU,
		MODE_SHOP
	};

	int m_nGameMode = MODE_LOCAL_MAP;

protected:
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;

	bool UpdateLocalMap(float fElapsedTime);
	bool UpdateMenu(float fElapsedTime);


	void UpdateStaticMap(float fElapsedTime);
	void HandleUserInput(float fElapsedTime);

public:
    void ChangeMap(string sMapName, float x, float y);
};
