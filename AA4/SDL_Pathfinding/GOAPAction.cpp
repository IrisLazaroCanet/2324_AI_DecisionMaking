#include "GOAPAction.h"

void GOAPAction::SetPreconditions(int idx, bool value)
{
	preconditions.values[idx] = value;
}

void GOAPAction::SetEffect(int idx, bool value)
{
	effects.values[idx] = value;
}

bool GOAPAction::IsAchievable(const GOAPWorldState& worldState) const
{
    for (size_t i = 0; i < preconditions.values.size(); ++i)
    {
        if (preconditions.values[i] && !worldState.values[i])
            return false;
    }
    return true;
}
