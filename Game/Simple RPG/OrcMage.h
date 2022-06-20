#pragma once

#include "Orc.h"
#include "Mage.h"

class OrcMage : public Orc
{

public:
	OrcMage(int lv) : Orc(lv) {			// Konstruktor
		id++;
		name =  "Ork Mag ";
		strength = 0;
		maxhp = 65 * lv;
		hp = maxhp;
		defence = 3;
		magic = 15 + 5 * lv;
		level = lv;
		exp = 10 * lv;
		damage = magic;
		action = 1;
		critical = 1 / 50 * magic;
	};
	~OrcMage();							// Destruktor
	void DestroyEnemy();				// Wywo³ywanie destruktora
};

