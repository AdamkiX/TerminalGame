#pragma once

#include "Weapon.h"

using namespace std;

class Sword : public Weapon
{

public:
	Sword(int level, int id);		// Konstruktor
	void DestroyItem();				// Wywoływanie destruktora
	~Sword();						// Destruktor
};

