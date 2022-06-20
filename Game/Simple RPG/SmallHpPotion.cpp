#include "SmallHpPotion.h"

SmallHpPotion::SmallHpPotion()
{
	name = "Ma³a mikstrua zdrowia";
	count = 0;
	hp = 60;
	goldValue = 30;
}

void SmallHpPotion::AddPots(int i)
{
	count += i;
}

SmallHpPotion::~SmallHpPotion()
{

}