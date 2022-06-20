#include "Chainmail.h"

Chainmail::Chainmail(int lv, int id)
{
	this->id++;
	weapon = false;
	armor = true;
	level = lv;
	name = "Kolczuga";
	class_ = "Wojownik";
	defence = 5 * lv;
	hp = 20 * lv;
	strength = 0;
	magic = lv;
	goldValue = 20 * lv;
}

Chainmail::~Chainmail()
{
	id--;
}

void Chainmail::DestroyItem()
{
	this->~Chainmail();
}