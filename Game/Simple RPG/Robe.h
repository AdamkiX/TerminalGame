#pragma once

#include "Armor.h"

using namespace std;

class Robe : public Armor
{


	// Metody
public:
	Robe(int level, int id);		// Konstruktor
	void DestroyItem();				// Wywo�ywanie destruktora
	~Robe();						// Destruktor
};

