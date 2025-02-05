#include "orc.h"


cDynamic_Creature_Orc::cDynamic_Creature_Orc(string name, float px, float py) : cDynamic_Creature(name)
{
	bFriendly = false;
	nHealth = 9;
	nHealthMax = 10;
	m_fStateTick = 2.0f;
	this->px = px;
	this->py = py;

	size = olc::vi2d(100,100);
	// pEquipedWeapon = (cWeapon*)Assets::get().GetItem("Basic Sword");
}

void cDynamic_Creature_Orc::PerformAttack()
{
}
