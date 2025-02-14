#pragma once

#include "cDynamics/cDynamics.h"

class cItem
{
public:
	cItem(string name, olc::Decal* decal, string desc);

	virtual bool OnInteract(cDynamic *object) {return false;}
	virtual bool OnUse(cDynamic *object) {return false;}

public:
	string sName;
	string sDescription;
	olc::Decal *pDecal;
	bool bKeyItem = false;
	bool bEquipable = false;

	static Engine *g_engine;
};