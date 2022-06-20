#pragma once

#include "Goblin.h"
#include "Rogue.h"

class GoblinRogue : public Goblin
{

public:
	GoblinRogue(int lv) : Goblin(level) {		// Konstruktor
		id++;
		name = "Goblin Z³odziej ";
		strength = 3 + 3 * lv;
		maxhp = 90 * lv;
		hp = maxhp;
		defence = 3;
		magic = 0;
		level = lv;
		exp = 8 * lv;
		damage = strength;
		action = 3;
	};
	~GoblinRogue();				// Destruktor
	void DestroyEnemy();		// Wywo³ywanie destruktora
};

