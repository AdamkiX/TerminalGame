#pragma once

#include "Weapon.h"

using namespace std;

class Staff : public Weapon
{
public:
	Staff(int level, int id);			// Konstruktor
	void DestroyItem();					// Wywo�ywanie destruktora
	~Staff();							// Destruktor
};

