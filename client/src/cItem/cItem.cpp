#include "cItem.h"

Engine* cItem::g_engine = nullptr;

cItem::cItem(string name, olc::Decal* decal, string desc) 
{ 
	sName = name; 
    pDecal = decal; 
    sDescription = desc; 
}
