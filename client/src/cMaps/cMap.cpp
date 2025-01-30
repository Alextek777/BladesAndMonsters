
#include "cMap.h"
#include <fstream>

cMap::cMap()
{

}

cMap::cMap(olc::PixelGameEngine *gfx) {
	pSprite = nullptr;
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

bool cMap::Create(string fileData, olc::Sprite* sprite, string name)
{
	sName = name;
	pSprite = sprite;
	ifstream data(fileData, ios::in | ios::binary);
	if (data.is_open())
	{
		data >> nWidth >> nHeight >> vTileSize.x >> vTileSize.y >> vOrigin.x >> vOrigin.y;
		// data >> vTileSize.x >> vTileSize.y;
		// data >> vOrigin.x >> vOrigin.y;

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