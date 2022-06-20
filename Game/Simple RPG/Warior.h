#ifndef WARIOR_H
#define WARIOR_H

using namespace std;

#include <string>
#include <iostream>
#include "Player.h"
#include "Enemy.h"

class Warior : public Player
{

public:
	int temp_def;
	// metody
	Warior(int lv);							// Konstruktor
	virtual void Ability(int turn);			// Umiejêtnoœæ specjalna
	virtual void LevelUp(int i);			// Ustawienie poziomu postaci
	virtual void DestroyPlayer();			// Wywo³ywanie destruktora
	~Warior();								// Destruktor
};

#endif