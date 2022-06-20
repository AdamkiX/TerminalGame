#pragma once

#include "Consumable.h"



using namespace std;

class SmallHpPotion : public Consumable
{

public:
	SmallHpPotion();			// Konstruktor
	void AddPots(int i);		// Zwiêksza licznik mikstur o 1
	~SmallHpPotion();			// Destruktor
};

