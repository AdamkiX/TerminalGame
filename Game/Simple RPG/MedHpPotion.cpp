#include "MedHpPotion.h"

MedHpPotion::MedHpPotion()
{
	name = "Œrednia mikstura zdrowia";
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