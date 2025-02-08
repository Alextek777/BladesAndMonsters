#pragma once
#include "../cMap.h"


class cMap_Village : public cMap
{
public:
	cMap_Village(olc::PixelGameEngine* gfx);

	bool PopulateDynamics(vector<cDynamic*> &vecDyns) override;
};

