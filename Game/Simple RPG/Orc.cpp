#include "Orc.h"

Orc::Orc(int lv)
{
	id++;
	name = "Ork";
	strength = 3 + 4 * lv;
	maxhp = 80 * lv;
	hp = maxhp;
	defence = 5;
	magic = 0;
	level = lv;
	exp = 4 * lv;
	damage = strength;
	action = 1;
	critical = 1 / 50 * strength;
}

void Orc::Critical()
{
	if (strength >= magic)
	{
		damage += strength * critical;
	}
	else
	damage += magic * critical;
}

void Orc::NormalDmg()
{
	if (strength >= magic)
	{
		damage = strength;
	}
	else
		damage = magic;
	
}

void Orc::Ability()
{

}

Orc::~Orc()
{
	id--;
}

void Orc::DestroyEnemy()
{
	this->~Orc();
}
