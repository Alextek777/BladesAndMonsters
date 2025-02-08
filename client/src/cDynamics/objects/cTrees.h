#pragma once
#include "../cDynamics.h"

class cDynamic_object_tree : public cDynamic_Object {
	int m_speed;
public:
    cDynamic_object_tree(string, float, float);
};

cDynamic_object_tree::cDynamic_object_tree(string name, float ox, float oy) : cDynamic_Object(name, ox, oy) {
    m_nGraphicCounter = rand() % 5;
    m_fTimerLimit = 0.2;

	bIsAttackable = false;
}