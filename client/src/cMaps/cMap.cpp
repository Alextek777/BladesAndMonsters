
#include "cMap.h"
#include <fstream>

cMap::cMap()
{

}

cMap::cMap(olc::PixelGameEngine *gfx) {
	nWidth = 0;
	nHeight = 0;
	m_solids = nullptr;
	m_indices = nullptr;

	this->gfx = gfx;
	backgroundLayer = gfx->CreateLayer();
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
	gfx->SetDrawTarget(backgroundLayer);

    auto ToScreen = [&](int x, int y)
    {			
        return olc::vi2d
        {
            (vOrigin.x * vTileSize.x) + (x - y) * (vTileSize.x / 2),
            (vOrigin.y * vTileSize.y) + (x + y) * (vTileSize.y / 2)
        };
    };

    gfx->Clear(olc::WHITE);
    gfx->SetPixelMode(olc::Pixel::MASK);
    for (int y = 0; y < nHeight; y++)
    {
        for (int x = 0; x < nWidth; x++)
        {
            olc::vi2d vWorld = ToScreen(x, y);


            // // TODO: refactor -> draw only visible tiles
            // if (vWorld.y > gfx->ScreenHeight() || vWorld.x > gfx->ScreenWidth()) {
            //     break;
            // }

            olc::Sprite* sprite = Assets::get().GetSprite(GetIndex(x, y));
            if (sprite == nullptr) {
                std::cerr << "unknown sprite index: " << GetIndex(x, y) << "\n";
                continue;
            }

            vWorld.y = vWorld.y - sprite->height + vTileSize.y;
    
            vWorld.x -= ox;
            vWorld.y -= oy;

            gfx->DrawSprite(vWorld, sprite);
        }
    }

    gfx->SetPixelMode(olc::Pixel::NORMAL);
	gfx->EnableLayer(backgroundLayer, true);
	gfx->SetDrawTarget(nullptr);

	return true;
}