#include "Warior.h"
#include <iostream>
#include <string>

Warior::Warior(int lv)
{
	name = "";
	_class = "Wojownik";
	strength = 5 + 6 * lv;
	maxhp = 100 * lv;
	hp = maxhp;
	defence = 10 + lv;
	magic = 0;
	maxequipment = 12;
	equipment = 0;
	level = lv;
	exp = 0;
	maxexp = lv * lv + 9;
	gold = 0;
	actions = 2;

	temp_def = defence;
}

void Warior::Ability(int turn_)
{
	if (turn_%3 == 1)
	{
		defence = INTMAX_MAX;
	}
	else
		defence = temp_def;
}

void Warior::LevelUp(int i)
{
	level = i;
	strength = 10 * level;
	maxhp = 100 * level;
	hp = maxhp;
	magic = 0;
	exp -= maxexp;
	maxexp = level * level + 9;

	temp_def = defence;
}

Warior::~Warior()
{
	
}

void Warior::DestroyPlayer()
{
	this->~Warior();
}