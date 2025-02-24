
#pragma once

#include "cAssets/cAssets.h"
#include "cDynamics/cDynamics.h"


#include <map>

using namespace std;

class cDynamic;

class cMap
{

public:
	cMap();
	~cMap();

public:
	int nWidth;
	int nHeight;
	string sName;

	// Size of single tile graphic
	olc::vi2d vTileSize;
	// Where to place tile (0,0) on screen (in tile size steps)
	olc::vi2d vOrigin;

	int GetIndex(int x, int y);
	bool Create(string fileData, string name);

	bool GetSolid(int x, int y);
	bool GetSolidWorld(int x, int y);

	bool Collides(cDynamic* dyn, float fElapsed);

	virtual bool PopulateDynamics(vector<cDynamic*> &vecDyns) {
		return false;
	}

	virtual bool DrawStaticMap(float ox, float oy);

	static olc::PixelGameEngine* g_engine;

protected:
	olc::vi2d ToScreen(int x, int y);
	olc::vi2d ToWorld(int x, int y);

protected:
	int *m_indices = nullptr;
	bool *m_solids = nullptr;
	int backgroundLayer;
};