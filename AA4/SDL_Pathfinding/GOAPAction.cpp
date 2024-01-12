#include "GOAPAction.h"

void GOAPAction::SetPreconditions(FactKey key, int value)
{
    preconditions.facts[key] = value;
}

void GOAPAction::SetEffect(FactKey key, int value)
{
    effects.facts[key] = value;
}

bool GOAPAction::IsAchievable(const GOAPWorldState& worldState) const
{
    for (const auto& precond : preconditions.facts)
    {
        FactKey key = precond.first;
        int precondValue = precond.second;

        auto worldStateIt = worldState.facts.find(key);
        if (worldStateIt == worldState.facts.end() || worldStateIt->second != precondValue)
        {
            return false;
        }
    }
    return true;
}
