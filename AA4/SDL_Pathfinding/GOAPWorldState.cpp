#include "GOAPWorldState.h"

void GOAPWorldState::SetFact(FactKey key, int value)
{
	facts[key] = value;
}

int GOAPWorldState::GetFact(FactKey key) const
{
    auto it = facts.find(key);

    // Check if the key exists in the map
    if (it != facts.end())
    {
        return it->second; // Return the value associated with the key
    }
    else
    {
        // Key not found, return a default value (you may want to handle this differently based on your requirements)
        return 0; // Default value, change as needed
    }
}

void GOAPWorldState::Clear()
{
	facts.clear();
}


//unused
/*
void GOAPWorldState::Set(std::vector<bool> _values)
{
    values = _values;
}
*/