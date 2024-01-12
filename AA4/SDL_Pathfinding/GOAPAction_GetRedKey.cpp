#include "GOAPAction_GetRedKey.h"

GOAPAction_GetRedKey::GOAPAction_GetRedKey()
{
	preconditions.SetFact(has_red_key, 0);

	effects.SetFact(has_red_key, 1);

	//cost = algo

	//TODO: Com expressar en fact que l'agent està a la mateixa room que la coin / pot accedir a la key?
}

GOAPAction_GetRedKey::~GOAPAction_GetRedKey()
{
}

void GOAPAction_GetRedKey::Update(Agent* agent, float dtime)
{
	//Aquí ha d'anar el codi de que l'agent va agafar la key
}
