#pragma once

#include "Enemy.h"
#include "Movement.h"

class Boss : public Enemy
{

// Metody
public:
	Boss(int level);		// Konstruktor
	void Ability();			// Umiejêtnoœæ specjalna
	~Boss();				// Destruktor
	void DestroyEnemy();	// Wywo³anie destruktora
};

