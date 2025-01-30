#pragma once
#include "cMap.h"


class cMap_Village : public cMap
{
public:
	cMap_Village();

	bool PopulateDynamics(vector<cDynamic*> &vecDyns) override;
	virtual bool DrawStaticMap(olc::PixelGameEngine *gfx) override;
};

