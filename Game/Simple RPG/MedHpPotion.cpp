#include "MedHpPotion.h"

MedHpPotion::MedHpPotion()
{
	name = "�rednia mikstura zdrowia";
	count = 0;
	hp = 300;
	goldValue = 150;
}

void MedHpPotion::AddPots(int i)
{
	count += i;
}

MedHpPotion::~MedHpPotion()
{

}