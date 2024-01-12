#pragma once
#include <vector>
#include <map>
#include <string>

enum FactKey
{
	has_coin = 0,
	agent_room,

	red_key_room,	//Same idx as enum Color
	orange_key_room,
	yellow_key_room,
	green_key_room,
	blue_key_room,
	purple_key_room,

	has_yellow_key,
	has_pink_key,
	has_green_key,
	has_red_key,
	has_blue_key,
	has_orange_key,	
	has_purple_key
};

class GOAPWorldState
{
public:
	std::map<FactKey, int> facts;

	GOAPWorldState() { }
	~GOAPWorldState() { }
	void SetFact(FactKey key, int value);
	int GetFact(FactKey key) const;
	void Clear();

	//UNUSED
	//std::vector<bool> values;
	//std::vector<bool> mask;
	//void Set(std::vector<bool> _values);
};