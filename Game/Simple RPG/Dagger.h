#pragma once

#include "Weapon.h"

using namespace std;

class Dagger : public Weapon
{
public:
	Dagger(int level, int id);		// Konstruktor
	void DestroyItem();				// Wywo³anie destruktora
	~Dagger();						// Destruktor
};	

