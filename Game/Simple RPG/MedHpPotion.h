#pragma once

#include "Consumable.h"



using namespace std;

class MedHpPotion : public Consumable
{
public:
	MedHpPotion();				// Konstruktor
	void AddPots(int i);		// Zwi�ksza licznik mikstur o 1
	~MedHpPotion();				// Destruktor
};

