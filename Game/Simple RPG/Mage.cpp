#include "Mage.h"
#include <iostream>
#include <string>

Mage::Mage(int lv)
{
	level = lv;
	name = "";
	_class = "Mag";
	strength = 2 * level;
	maxhp = 65 * level;
	hp = maxhp;
	defence = 4;
	magic = 15 + 8 * level;
	maxequipment = 7;
	equipment = 0;
	maxexp = level * level + 9;
	exp = 0;
	gold = 0;
	actions = 1;

	temp_mag = magic;
}

void Mage::Ability(int turn_)
{
	if (turn_ == 1)
	{
		magic *= 4;
	}
	else
		magic = temp_mag;
}

void Mage::LevelUp(int i)
{
	level = i;
	strength = 2 * level;
	maxhp = 65 * level;
	hp = maxhp;
	magic = 15 + 5 * level;
	exp -= maxexp;
	maxexp = level * level + 9;

	temp_mag = magic;
}

Mage::~Mage()
{

}

void Mage::DestroyPlayer()
{
	this->~Mage();
}