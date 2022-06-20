#include "Boss.h"

Boss::Boss(int lv)
{
	id++;
	name = "W³adca Potworów";
	strength = 30 + 8 * lv;
	maxhp = 200 * lv;
	hp = maxhp;
	defence = 30;
	magic = 0;
	level = lv;
	exp = 100 * lv;
	damage = strength;
	action = 4;
}

void Boss::Ability()
{

}

Boss::~Boss()
{
	
}

void Boss::DestroyEnemy()
{
	this->~Boss();
}