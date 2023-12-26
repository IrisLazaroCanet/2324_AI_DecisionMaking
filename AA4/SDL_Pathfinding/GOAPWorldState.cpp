#include "GOAPWorldState.h"

void GOAPWorldState::Set(std::vector<bool> _values)
{
	values = _values;
}

void GOAPWorldState::Clear()
{
	values.clear();
}
