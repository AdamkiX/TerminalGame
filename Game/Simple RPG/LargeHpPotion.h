#pragma once

#include "Consumable.h"



using namespace std;

class LargeHpPotion : public Consumable
{
public:
	LargeHpPotion();			// Konstruktor
	void AddPots(int i);		// Zwi�ksza licznik mikstur o 1
	~LargeHpPotion();			// Destruktor
};

