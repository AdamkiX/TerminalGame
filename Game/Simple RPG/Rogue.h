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
	virtual void Ability(int i);		// Umiej�tno�� specjalna
	virtual void LevelUp(int i);		// Ustawienie poziomu postaci
	virtual void DestroyPlayer();		// Wywo�ywanie destruktora
	~Rogue();							// Destruktor
};

#endif

