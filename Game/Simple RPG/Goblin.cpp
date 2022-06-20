#include "Goblin.h"

Goblin::Goblin(int lv)
{
	id++;
	name = "Goblin";
	strength = 2 + 2 * lv;
	maxhp = 60 * lv;
	hp = maxhp;
	defence = 3;
	magic = 0;
	level = lv;
	exp = 2 * lv;
	damage = strength;
	action = 4;
}

void Goblin::ActionPerTurnNerf()
{
	if (action > 1)
	{
		action--;
	}
}

Goblin::~Goblin()
{
	id--;
}

void Goblin::DestroyEnemy()
{
	this->~Goblin();
}

void Goblin::Ability()
{

}