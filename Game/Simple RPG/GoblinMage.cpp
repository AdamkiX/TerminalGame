#include "GoblinMage.h"

GoblinMage::~GoblinMage()
{
	id--;
}

void GoblinMage::DestroyEnemy()
{
	this->~GoblinMage();
}