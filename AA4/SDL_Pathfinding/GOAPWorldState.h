#pragma once
#include <vector>

class GOAPWorldState
{
public:
	std::vector<bool> values;
	std::vector<bool> mask;

	GOAPWorldState() { }
	~GOAPWorldState() { }
	void Set(std::vector<bool> _values);
	void Clear();


	bool GOAPWorldState::operator==(const GOAPWorldState& other) const
	{
		return this->values == other.values;
	}

	bool GOAPWorldState::operator!=(const GOAPWorldState& other) const
	{
		return !(*this == other);
	}

};