#pragma once
#include "PointerState.h"

class PointerStateTemplate : public PointerState
{
public:
	virtual void Enter();
	virtual void Update();
	virtual void Exit();
};