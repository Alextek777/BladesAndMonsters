#include "witty.h"

cDynamic_Creature_Witty::cDynamic_Creature_Witty() : cDynamic_Creature("witty")
{
	bFriendly = true;
	nHealth = 9;
	nHealthMax = 10;
	m_fStateTick = 2.0f;
	// pEquipedWeapon = (cWeapon*)Assets::get().GetItem("Basic Sword");
}

void cDynamic_Creature_Witty::PerformAttack()
{
	m_nGraphicState = ATTACKING;
	m_nGraphicCounter = 1;
	// if (pEquipedWeapon == nullptr)
	// 	return;

	// pEquipedWeapon->OnUse(this);
}
