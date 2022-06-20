#include "Dagger.h"

Dagger::Dagger(int lv, int id)
{
	this->id++;
	armor = false;
	weapon = true;
	level = lv;
	name = "Sztylet";
	class_ = "Z³odziej";
	defence = 0;
	hp = 0;
	strength = 3 * lv;
	magic = 3 * lv;
	goldValue = 20 * lv;
}

Dagger::~Dagger()
{
	id--;
}

void Dagger::DestroyItem()
{
	this->~Dagger();
}