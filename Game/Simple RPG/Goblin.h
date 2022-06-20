#pragma once

#include "Enemy.h"

class Goblin : public Enemy
{

public:
	Goblin(int lv);					// Konstruktor
	void ActionPerTurnNerf();		// Usuwanie co tur� maksymalnej ilo�ci tur
	void DestroyEnemy();			// Wywo�ywanie destruktora
	~Goblin();						// Destruktor
	void Ability();					// Umiej�tno�� specjalna
};

