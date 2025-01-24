#include "cMapVillage.h"


cMap_Village::cMap_Village()
{
	Create("maps/village.lvl", Assets::get().GetSprite("village"), "village");
}