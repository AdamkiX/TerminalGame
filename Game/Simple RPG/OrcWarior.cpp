#include "OrcWarior.h"

OrcWarior::~OrcWarior()
{
	id--;
}

void OrcWarior::DestroyEnemy()
{
	this->~OrcWarior();
}