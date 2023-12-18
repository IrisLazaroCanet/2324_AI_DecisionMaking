#pragma once
#include "PointerStateTemplate.h"
#include <iostream>

class State_FleeEnemy : public PointerStateTemplate
{
public:
	void Enter() override;
	void Update() override;
	void Exit() override;
};