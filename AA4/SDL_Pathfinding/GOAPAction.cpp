#include "GOAPAction.h"

void GOAPAction::SetPreconditions(int idx, bool value)
{
	preconditions.values[idx] = value;
}

void GOAPAction::SetEffect(int idx, bool value)
{
	effects.values[idx] = value;
}
