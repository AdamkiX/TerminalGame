#pragma once

#include "Enemy.h"

class Orc : public Enemy
{
protected:
	int critical;

public:
	Orc(int lv);				// Konstruktor
	void Critical();			// Zadanie krytycznych obra¿eñ
	void NormalDmg();			// Zadanie zwyk³ego obra¿enia
	void Ability();				// U¿ycie umiejêtnoœci specjalnej
	void DestroyEnemy();		// Wywo³anie destruktora
	~Orc();						// Destruktor
};

