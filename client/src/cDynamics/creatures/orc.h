#pragma once
#include "../cDynamics.h"

class cDynamic_Creature_Orc : public cDynamic_Creature
{
public:
	cDynamic_Creature_Orc(string name, float px, float py);

public:
	void PerformAttack() override;
};