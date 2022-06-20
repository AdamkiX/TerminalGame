#pragma once

#include "Armor.h"

using namespace std;

class Chainmail : public Armor
{
	// Metody
public:
	Chainmail(int level, int id);	// Konstruktor
	void DestroyItem();				// Wywo³anie destruktora
	~Chainmail();					// Destruktor
};	

