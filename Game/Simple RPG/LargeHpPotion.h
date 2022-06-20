#pragma once

#include "Consumable.h"



using namespace std;

class LargeHpPotion : public Consumable
{
public:
	LargeHpPotion();			// Konstruktor
	void AddPots(int i);		// Zwiêksza licznik mikstur o 1
	~LargeHpPotion();			// Destruktor
};

