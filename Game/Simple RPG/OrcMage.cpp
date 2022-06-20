#include "OrcMage.h"


OrcMage::~OrcMage()
{
	id--;
}

void OrcMage::DestroyEnemy()
{
	this->~OrcMage();
}