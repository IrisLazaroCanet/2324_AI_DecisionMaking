#include "GOAPAction_GetCoin.h"

GOAPAction_GetCoin::GOAPAction_GetCoin()
{
	preconditions.SetFact(has_coin, 0);

	effects.SetFact(has_coin, 1);

	cost = 4.0f;

	//TODO: Com expressar en fact que l'agent està a la mateixa room que la coin / pot accedir a la coin?
}

GOAPAction_GetCoin::~GOAPAction_GetCoin()
{
}

void GOAPAction_GetCoin::Update(Agent* agent, float dtime)
{
	//Aquí ha d'anar el codi de que l'agent va agafar la coin
	std::cout << "Get coin" << std::endl;
}
