
#include "cMap.h"
#include <fstream>

#include <cmath>

olc::PixelGameEngine* cMap::g_engine = nullptr;

cMap::cMap() {
	nWidth = 0;
	nHeight = 0;
	m_solids = nullptr;
	m_indices = nullptr;

	backgroundLayer = g_engine->CreateLayer();
}

cMap::~cMap()
{
	delete[] m_solids;
	delete[] m_indices;
}

int cMap::GetIndex(int x, int y)
{
	if (x >= 0 && x < nWidth && y >= 0 && y < nHeight)
		return m_indices[y*nWidth + x];
	else
		return 0;
}

bool cMap::GetSolid(int x, int y)
{
	if (x >= 0 && x < nWidth && y >= 0 && y < nHeight)
		return m_solids[y*nWidth + x];
	else
		return true;
}

bool cMap::GetSolidWorld(int x, int y) {
	olc::vi2d world = ToWorld(x, y);
	return GetSolid(world.x, world.y);
}

bool cMap::Collides(cDynamic* dyn, float fElapsed) {
	if (!dyn->bSolidVsMap) {
		return false;
	}

	if (dyn->vx == 0 && dyn->vy == 0) {
		return false;
	}

	int futureX = dyn->px + dyn->vx * fElapsed;
	int futureY = dyn->py + dyn->vy * fElapsed;


	// Upper left corner check
	if (GetSolidWorld(futureX, futureY)) {
		return true;
	}

	// Upper right corner check
	if (GetSolidWorld(futureX + dyn->size.x, futureY)) {
		return true;
	}

	// Lowwer left corner check
	if (GetSolidWorld(futureX, futureY + dyn->size.y)) {
		return true;
	}

	// Lowwer right corner check
	if (GetSolidWorld(futureX + dyn->size.x, futureY + dyn->size.y)) {
		return true;
	}

	return false;
}

bool cMap::Create(string fileData, string name)
{
	sName = name;
	ifstream data(fileData, ios::in | ios::binary);
	if (data.is_open())
	{
		data >> nWidth >> nHeight >> vTileSize.x >> vTileSize.y >> vOrigin.x >> vOrigin.y;

		m_solids = new bool[nWidth * nHeight];
		m_indices = new int[nWidth * nHeight];
		for (int i = 0; i < nWidth * nHeight; i++)
		{
			data >> m_indices[i];
			data >> m_solids[i];
		}
		return true;
	}

	return false;
}

bool cMap::DrawStaticMap(float ox, float oy) {
    g_engine->SetDrawTarget(backgroundLayer);
    g_engine->Clear(olc::WHITE);
    g_engine->SetPixelMode(olc::Pixel::MASK);


    int minX = std::max(0, ToWorld(ox, oy).x - 1);
    int minY = std::max(0, ToWorld(ox + g_engine->ScreenWidth(), oy).y - 1);
    int maxX = std::min(nWidth, ToWorld(ox + g_engine->ScreenWidth(), oy + g_engine->ScreenHeight()).x + 2);
    int maxY = std::min(nHeight, ToWorld(ox, oy + g_engine->ScreenHeight()).y + 2);

    for (int y = minY; y < maxY; y++) {
        for (int x = minX; x < maxX; x++) {
            olc::vi2d vWorld = ToScreen(x, y);

            olc::Sprite* sprite = Assets::get().GetSprite(GetIndex(x, y));
            if (sprite == nullptr) {
                std::cerr << "unknown sprite index: " << GetIndex(x, y) << "\n";
                continue;
            }

            vWorld.y = vWorld.y - sprite->height + vTileSize.y;
            vWorld.x -= ox;
            vWorld.y -= oy;

            g_engine->DrawSprite(vWorld, sprite);
        }
    }

    g_engine->SetPixelMode(olc::Pixel::NORMAL);
    g_engine->EnableLayer(backgroundLayer, true);
    g_engine->SetDrawTarget(nullptr);

    return true;
}

olc::vi2d cMap::ToScreen(int x, int y){			
	return olc::vi2d {
		(vOrigin.x * vTileSize.x) + (x - y) * (vTileSize.x / 2),
		(vOrigin.y * vTileSize.y) + (x + y) * (vTileSize.y / 2)
	};
};

olc::vi2d cMap::ToWorld(int screen_x, int screen_y) {
	int adjusted_x = screen_x - (vOrigin.x * vTileSize.x);
	int adjusted_y = screen_y - (vOrigin.y * vTileSize.y);

	int x = (adjusted_x / (vTileSize.x / 2) + adjusted_y / (vTileSize.y / 2)) / 2;
	int y = (adjusted_y / (vTileSize.y / 2) - adjusted_x / (vTileSize.x / 2)) / 2;

	return olc::vi2d{x, y};
};