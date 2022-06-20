#include "Robe.h"

Robe::Robe(int lv, int id)
{
	this->id++;
	weapon = false;
	armor = true;
	level = lv;
	name = "Szata";
	class_ = "Mag";
	defence = lv;
	hp = 10 * lv;
	strength = lv/2;
	magic = 2 * lv;
	goldValue = 30 * lv;
}

Robe::~Robe()
{
	id--;
}

void Robe::DestroyItem()
{
	this->~Robe();
}