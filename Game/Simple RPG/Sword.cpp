#include "Sword.h"

Sword::Sword(int lv,int id)
{
	this->id++;
	armor = false;
	weapon = true;
	level = lv;
	name = "Miecz";
	class_ = "Wojownik";
	defence = 0;
	hp = 0;
	strength = 5 *lv;
	magic = 0;
	goldValue = 30 * lv;
}

Sword::~Sword()
{
	id--;
}

void Sword::DestroyItem()
{
	this->~Sword();
}