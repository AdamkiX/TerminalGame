#pragma once

#include "Consumable.h"



using namespace std;

class MedHpPotion : public Consumable
{
public:
	MedHpPotion();				// Konstruktor
	void AddPots(int i);		// Zwiêksza licznik mikstur o 1
	~MedHpPotion();				// Destruktor
};

