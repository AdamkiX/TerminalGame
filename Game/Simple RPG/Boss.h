#pragma once

#include "Enemy.h"
#include "Movement.h"

class Boss : public Enemy
{

// Metody
public:
	Boss(int level);		// Konstruktor
	void Ability();			// Umiejętność specjalna
	~Boss();				// Destruktor
	void DestroyEnemy();	// Wywołanie destruktora
};

