
#pragma once

#include "cMaps/cAssets.h"
#include "cDynamics/cDynamics.h"

using namespace std;

class cMap
{

public:
	enum NATURE
	{
		TALK,
		WALK
	};

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

	virtual bool PopulateDynamics(vector<cDynamic*> &vecDyns)
	{
		return false;
	}

	virtual bool OnInteraction(vector<cDynamic*> &vecDynobs, cDynamic *target, NATURE nature)
	{
		return false;
	}

private:
	int *m_indices = nullptr;
	bool *m_solids = nullptr;
};

class cMap_Village1 : public cMap
{
public:
	cMap_Village1();

	bool PopulateDynamics(vector<cDynamic*> &vecDyns) override;
	bool OnInteraction(vector<cDynamic*> &vecDynobs, cDynamic *target, NATURE nature) override;
};