#include "cMapVillage.h"
#include "cDynamics/creatures/orc.h"
#include "cDynamics/objects/cClouds.h"
#include "cDynamics/objects/cTrees.h"

cMap_Village::cMap_Village(olc::PixelGameEngine* gfx) : cMap(gfx)
{
	Create("maps/village.lvl", "village");
}


bool cMap_Village::PopulateDynamics(vector<cDynamic*> &vecDyns) {
	// Add Teleporters

	vecDyns.push_back(new cDynamic_object_tree("TreeAutumn", 240, 200));
	vecDyns.push_back(new cDynamic_object_tree("TreeAutumn", 200, 240));
	vecDyns.push_back(new cDynamic_object_tree("TreeAutumn", 280, 240));


    vecDyns.push_back(new cDynamic_Creature_Orc("orc", 300, 300));

    vecDyns.push_back(new cDynamic_object_cloud("cloud", 100, 140));
	vecDyns.push_back(new cDynamic_object_cloud("cloud", 130, 170));
	vecDyns.push_back(new cDynamic_object_cloud("cloud", 170, 100));
	vecDyns.push_back(new cDynamic_object_cloud("cloud", 50, 70));
	vecDyns.push_back(new cDynamic_object_cloud("cloud", 150, 210));



	for (int i = 0; i< 30; i++) {
		vecDyns.push_back(new cDynamic_object_cloud("cloud", 50 + rand() % 350, 50 + rand() % 350));
	}

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