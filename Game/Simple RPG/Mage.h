#ifndef MAGE_H
#define MAGE_H

using namespace std;

#include <string>
#include <iostream>
#include "Player.h"
#include "Enemy.h"

class Mage : public Player
{
public:
	int temp_mag;
	// metody
	Mage(int lv);						// Konstruktor
	virtual void Ability(int i);		// Umiejêtnoœæ specjalna
	virtual void LevelUp(int i);		// Ustawienie poziomu postaci
	virtual void DestroyPlayer();		// Wywo³anie destruktora
	~Mage();							// Destruktor
};

#endif

