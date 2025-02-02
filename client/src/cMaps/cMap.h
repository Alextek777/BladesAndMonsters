
#pragma once

#include "cAssets/cAssets.h"
#include "cDynamics/cDynamics.h"

using namespace std;

class cDynamic;

class cMap
{

public:
	cMap();
	cMap(olc::PixelGameEngine *gfx);
	~cMap();

public:
	int nWidth;
	int nHeight;
	string sName;
	olc::Sprite* pSprite;

	// Size of single tile graphic
	olc::vi2d vTileSize;
	// Where to place tile (0,0) on screen (in tile size steps)
	olc::vi2d vOrigin;

	int GetIndex(int x, int y);
	bool GetSolid(int x, int y);
	bool Create(string fileData, olc::Sprite* sprite, string name);



	virtual bool PopulateDynamics(vector<cDynamic*> &vecDyns) {
		return false;
	}

	virtual bool DrawStaticMap(float ox, float oy) {
		return false;
	}

protected:
	int *m_indices = nullptr;
	bool *m_solids = nullptr;

	olc::PixelGameEngine *gfx;
	int backgroundLayer;
};