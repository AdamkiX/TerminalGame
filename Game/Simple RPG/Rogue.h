#ifndef ROGUE_H
#define ROGUE_H

using namespace std;

#include <string>
#include <iostream>
#include "Player.h"
#include "Enemy.h"

class Rogue : public Player
{
public:
	// metody

	Rogue(int lv);						// Konstruktor
	virtual void Ability(int i);		// Umiejêtnoœæ specjalna
	virtual void LevelUp(int i);		// Ustawienie poziomu postaci
	virtual void DestroyPlayer();		// Wywo³ywanie destruktora
	~Rogue();							// Destruktor
};

#endif

