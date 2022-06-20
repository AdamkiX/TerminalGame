#pragma once

#include "Orc.h"
#include "Warior.h"

class OrcWarior : public Orc
{

public:
	OrcWarior(int lv) : Orc(level)			// Konstruktor
	{
		id++;
		name = "Ork Wojownik";
		strength = 7 + 7 * lv;
		maxhp = 120 * lv;
		hp = maxhp;
		defence = 5 * lv;
		magic = 0;
		level = lv;
		exp = 14 * lv;
		damage = strength;
		action = 2;
	};
	~OrcWarior();							// Destruktor
	void DestroyEnemy();					// Wywo³anie destruktora
};

