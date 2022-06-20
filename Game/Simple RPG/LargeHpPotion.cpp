#include "LargeHpPotion.h"

LargeHpPotion::LargeHpPotion()
{
	name = "Du¿a mikstura zdrowia";
	count = 0;
	hp = 1500;
	goldValue = 500;
}

void LargeHpPotion::AddPots(int i)
{
	count += i;
}

LargeHpPotion::~LargeHpPotion()
{

}