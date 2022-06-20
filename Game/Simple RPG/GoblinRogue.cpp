#include "GoblinRogue.h"

GoblinRogue::~GoblinRogue()
{
	id--;
}

void GoblinRogue::DestroyEnemy()
{
	this->~GoblinRogue();
}