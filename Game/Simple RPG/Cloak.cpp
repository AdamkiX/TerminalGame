#include "Cloak.h"

Cloak::Cloak(int lv, int id)
{
	this->id++;
	weapon = false;
	armor = true;
	level = lv;
	name = "P³aszcz";
	class_ = "Z³odziej";
	defence = 3 * lv;
	hp = 15 * lv;
	strength = 2 * lv;
	magic = 2 * lv;
	goldValue = 15 * lv;
}

Cloak::~Cloak()
{
	id--;
}

void Cloak::DestroyItem()
{
	this->~Cloak();
}	
