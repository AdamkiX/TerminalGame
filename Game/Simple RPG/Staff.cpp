#include "Staff.h"

Staff::Staff(int lv, int id)
{
	this->id++;
	armor = false;
	weapon = true;
	level = lv;
	name = "Magiczny kij";
	class_ = "Mag";
	defence = 0;
	hp = 0;
	strength = lv;
	magic = 5 * lv;
	goldValue = 15 * lv;
}

Staff::~Staff()
{
	id--;
}

void Staff::DestroyItem()
{
	this->~Staff();
}