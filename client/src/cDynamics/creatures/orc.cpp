#include "orc.h"


cDynamic_Creature_Orc::cDynamic_Creature_Orc(string name, float px, float py) : cDynamic_Creature(name)
{
	bFriendly = false;
	nHealth = 7;
	nHealthMax = 10;
	m_fStateTick = 2.0f;
	this->px = px;
	this->py = py;

	// pEquipedWeapon = (cWeapon*)Assets::get().GetItem("Basic Sword");
}

void cDynamic_Creature_Orc::PerformAttack()
{
}
