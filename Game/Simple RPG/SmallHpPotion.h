#pragma once

#include "Consumable.h"



using namespace std;

class SmallHpPotion : public Consumable
{

public:
	SmallHpPotion();			// Konstruktor
	void AddPots(int i);		// Zwi�ksza licznik mikstur o 1
	~SmallHpPotion();			// Destruktor
};

