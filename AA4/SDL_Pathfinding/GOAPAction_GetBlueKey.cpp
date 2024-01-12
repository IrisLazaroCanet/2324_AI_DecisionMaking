#include "GOAPAction_GetBlueKey.h"

GOAPAction_GetBlueKey::GOAPAction_GetBlueKey()
{
	preconditions.SetFact(has_blue_key, 0);

	effects.SetFact(has_blue_key, 1);

	//cost = algo

	//TODO: Com expressar en fact que l'agent està a la mateixa room que la coin / pot accedir a la coin?
}

GOAPAction_GetBlueKey::~GOAPAction_GetBlueKey()
{
}

void GOAPAction_GetBlueKey::Update(Agent* agent, float dtime)
{
	//Aquí ha d'anar el codi de que l'agent va agafar la key
}
