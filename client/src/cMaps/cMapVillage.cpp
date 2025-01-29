#include "cMapVillage.h"


cMap_Village::cMap_Village()
{
	Create("maps/village.lvl", Assets::get().GetSprite("village"), "village");
}


bool cMap_Village::PopulateDynamics(vector<cDynamic*> &vecDyns) {
	// Add Teleporters
	vecDyns.push_back(new cDynamic_Object("TreeAutumn", 200, 200));
	vecDyns.push_back(new cDynamic_Object("TreeAutumn", 240, 200));
	vecDyns.push_back(new cDynamic_Object("TreeAutumn", 200, 240));
	vecDyns.push_back(new cDynamic_Object("TreeAutumn", 280, 240));

	// // Add Items
	// vecDyns.push_back(new cDynamic_Item(10, 10, RPG_Assets::get().GetItem("Small Health")));
	// vecDyns.push_back(new cDynamic_Item(12, 10, RPG_Assets::get().GetItem("Health Boost")));

	// for (int i = 0; i < 3; i++)
	// {
	// 	cDynamic* g1 = new cDynamic_Creature_Skelly();
	// 	vecDyns.push_back(g1);
	// 	g1->px = rand() % 10 + 5.0f;
	// 	g1->py = rand() % 10 + 5.0f;
	// }

	return true;
}