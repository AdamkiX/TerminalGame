#pragma once

#include "Enemy.h"
#include "Movement.h"

class Boss : public Enemy
{

// Metody
public:
	Boss(int level);		// Konstruktor
	void Ability();			// Umiej�tno�� specjalna
	~Boss();				// Destruktor
	void DestroyEnemy();	// Wywo�anie destruktora
};

