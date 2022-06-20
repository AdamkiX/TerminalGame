#pragma once

#include "Enemy.h"

class Orc : public Enemy
{
protected:
	int critical;

public:
	Orc(int lv);				// Konstruktor
	void Critical();			// Zadanie krytycznych obra�e�
	void NormalDmg();			// Zadanie zwyk�ego obra�enia
	void Ability();				// U�ycie umiej�tno�ci specjalnej
	void DestroyEnemy();		// Wywo�anie destruktora
	~Orc();						// Destruktor
};

