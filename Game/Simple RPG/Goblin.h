#pragma once

#include "Enemy.h"

class Goblin : public Enemy
{

public:
	Goblin(int lv);					// Konstruktor
	void ActionPerTurnNerf();		// Usuwanie co turê maksymalnej iloœci tur
	void DestroyEnemy();			// Wywo³ywanie destruktora
	~Goblin();						// Destruktor
	void Ability();					// Umiejêtnoœæ specjalna
};

