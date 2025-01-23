
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

	ChangeMap("coder town", 5, 5);
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
    // Draw Level
	int nTileWidth = 16;
	int nTileHeight = 16;
	int nVisibleTilesX = ScreenWidth() / nTileWidth;
	int nVisibleTilesY = ScreenHeight() / nTileHeight;

	// Calculate Top-Leftmost visible tile
	float fOffsetX = fCameraPosX - (float)nVisibleTilesX / 2.0f;
	float fOffsetY = fCameraPosY - (float)nVisibleTilesY / 2.0f;

	// Clamp camera to game boundaries
	if (fOffsetX < 0) fOffsetX = 0;
	if (fOffsetY < 0) fOffsetY = 0;
	if (fOffsetX > m_pCurrentMap->nWidth - nVisibleTilesX) fOffsetX = m_pCurrentMap->nWidth - nVisibleTilesX;
	if (fOffsetY > m_pCurrentMap->nHeight - nVisibleTilesY) fOffsetY = m_pCurrentMap->nHeight - nVisibleTilesY;

	// Get offsets for smooth movement
	float fTileOffsetX = (fOffsetX - (int)fOffsetX) * nTileWidth;
	float fTileOffsetY = (fOffsetY - (int)fOffsetY) * nTileHeight;

	// Draw visible tile map
	for (int x = -1; x < nVisibleTilesX + 1; x++)
	{
		for (int y = -1; y < nVisibleTilesY + 1; y++)
		{
			int idx = m_pCurrentMap->GetIndex(x + fOffsetX, y + fOffsetY);
			int sx = idx % 10;
			int sy = idx / 10;

			DrawPartialSprite(x * nTileWidth - fTileOffsetX, y * nTileHeight - fTileOffsetY, m_pCurrentMap->pSprite, sx * nTileWidth, sy * nTileHeight, nTileWidth, nTileHeight);
		}
	}

	return true;
}

void Engine::ChangeMap(string sMapName, float x, float y)
{
	m_pCurrentMap = Assets::get().GetMap(sMapName);
	m_pCurrentMap->PopulateDynamics(m_vecDynamics);
}