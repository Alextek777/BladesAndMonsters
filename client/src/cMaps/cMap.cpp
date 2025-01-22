
#include "cMap.h"
#include <fstream>

#define X(n) g_script->AddCommand(new cCommand_ ## n)

cMap::cMap()
{
	pSprite = nullptr;
	nWidth = 0;
	nHeight = 0;
	m_solids = nullptr;
	m_indices = nullptr;
}


cMap::~cMap()
{
	delete[] m_solids;
	delete[] m_indices;
}

int cMap::GetIndex(int x, int y)
{
	if (x >= 0 && x < nWidth && y >= 0 && y < nHeight)
		return m_indices[y*nWidth + x];
	else
		return 0;
}

bool cMap::GetSolid(int x, int y)
{
	if (x >= 0 && x < nWidth && y >= 0 && y < nHeight)
		return m_solids[y*nWidth + x];
	else
		return true;
}

bool cMap::Create(string fileData, olc::Sprite* sprite, string name)
{
	sName = name;
	pSprite = sprite;
	ifstream data(fileData, ios::in | ios::binary);
	if (data.is_open())
	{
		data >> nWidth >> nHeight;
		m_solids = new bool[nWidth * nHeight];
		m_indices = new int[nWidth * nHeight];
		for (int i = 0; i < nWidth * nHeight; i++)
		{
			data >> m_indices[i];
			data >> m_solids[i];
		}
		return true;
	}

	return false;
}

cMap_Village1::cMap_Village1()
{
	Create("rpgdata/map/village1.lvl", RPG_Assets::get().GetSprite("village"), "coder town");
}

bool cMap_Village1::PopulateDynamics(vector<cDynamic*> &vecDyns)
{
	// // Add Teleporters
	// vecDyns.push_back(new cDynamic_Teleport(12.0f, 6.0f, "home", 5.0f, 12.0f));

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


bool cMap_Village1::OnInteraction(vector<cDynamic*> &vecDynobs, cDynamic *target, NATURE nature)
{
	// if (target->sName == "Teleport")
	// 	g_script->AddCommand(new cCommand_ChangeMap(
	// 		((cDynamic_Teleport*)target)->sMapName,
	// 		((cDynamic_Teleport*)target)->fMapPosX,
	// 		((cDynamic_Teleport*)target)->fMapPosY));

	return false;
}





