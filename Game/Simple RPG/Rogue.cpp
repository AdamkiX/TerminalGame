#include "Rogue.h"
#include <iostream>
#include <string>

Rogue::Rogue(int lv)
{
	name = "";
	_class = "Z³odziej";
	strength = 3 + 8 * lv;
	maxhp = 80 * lv;
	hp = maxhp;
	defence = 7;
	magic = 5;
	maxequipment = 17;
	equipment = 0;
	level = lv;
	maxexp = lv * lv - 2 * lv + 9;
	exp = 0;
	gold = 0;
	actions = 3;
}

void Rogue::Ability(int turn_)
{
	if (turn_ == 1)
	{
		actions = 5;
	}
}

void Rogue::LevelUp(int i)
{
	level = i;
	strength = 7 * level;
	maxhp = 80 * level;
	hp = maxhp;
	magic = 5 + 2 * level;
	exp -= maxexp;
	maxexp = level * level - 2 * level + 9;
}

Rogue::~Rogue()
{

}

void Rogue::DestroyPlayer()
{
	this->~Rogue();
}