#include "GOAPWorldState.h"

/*
void GOAPWorldState::Set(std::vector<bool> _values)
{
	values = _values;
}
*/

void GOAPWorldState::SetFact(FactKey key, int value)
{
	facts[key] = value;
}

void GOAPWorldState::Clear()
{
	facts.clear();
}
