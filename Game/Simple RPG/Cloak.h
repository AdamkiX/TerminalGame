#pragma once

#include "Armor.h"

using namespace std;

class Cloak : public Armor
{

	// Metody
public:
	Cloak(int level, int id);		// Konstruktor
	~Cloak();						// Destruktor
	void DestroyItem();				// Wywo³anie destruktora
};

