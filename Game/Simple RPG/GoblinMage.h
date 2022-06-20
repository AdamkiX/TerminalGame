#pragma once

#include "Goblin.h"
#include "Mage.h"

class GoblinMage : public Goblin
{

public:
	GoblinMage(int lv) : Goblin(lv) {	// Konstruktor
		id++;
		name = "Goblin Mag" ;
		strength = 0;
		maxhp = 80 * lv;
		hp = maxhp;
		defence = 3;
		magic = 15 + 4 * lv;
		level = lv;
		exp = 9 * lv;
		damage = magic;
		action = 2;
	};
	void DestroyEnemy();	// Wywo³anie destruktora
	~GoblinMage();			// Destruktor
};

