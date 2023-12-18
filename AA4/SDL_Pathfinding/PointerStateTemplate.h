#pragma once
#include "PointerState.h"

class PointerStateTemplate : public PointerState
{
public:
	virtual void Enter() = 0;
	virtual void Update() = 0;
	virtual void Exit() = 0;
};