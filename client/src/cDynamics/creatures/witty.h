#pragma once
#include "../cDynamics.h"

class cDynamic_Creature_Witty : public cDynamic_Creature
{
public:
	cDynamic_Creature_Witty();

public:
	void PerformAttack() override;
};