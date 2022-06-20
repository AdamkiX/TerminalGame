#pragma once

#include "Weapon.h"

using namespace std;

class Sword : public Weapon
{

public:
	Sword(int level, int id);		// Konstruktor
	void DestroyItem();				// Wywo³ywanie destruktora
	~Sword();						// Destruktor
};

