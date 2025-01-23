
#pragma once

#include "cMaps/cAssets.h"
#include "cDynamics/cDynamics.h"

using namespace std;

class cMap
{

public:
	cMap();
	~cMap();

public:
	int nWidth;
	int nHeight;
	string sName;
	olc::Sprite* pSprite;

	int GetIndex(int x, int y);
	bool GetSolid(int x, int y);
	bool Create(string fileData, olc::Sprite* sprite, string name);

private:
	int *m_indices = nullptr;
	bool *m_solids = nullptr;
};