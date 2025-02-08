#pragma once
#include "../cDynamics.h"

class cDynamic_object_cloud : public cDynamic_Object {
public:
    cDynamic_object_cloud(string, float, float);
};

cDynamic_object_cloud::cDynamic_object_cloud(string name, float px, float py) : cDynamic_Object(name, px, py) {
	m_nGraphicCounter = rand() % 5;
	vx = 5 + rand() % 10;
	vy = 0;

	m_nGraphicCounter = 0;
	bIsAttackable = false;
	m_fTimerLimit = 0.6;
}