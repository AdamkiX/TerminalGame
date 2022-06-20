#pragma once

#include "Inventory.h"
#include "LevelGen.h"
#include "Chainmail.h"
#include "Cloak.h"
#include "Robe.h"
#include "Sword.h"
#include "Dagger.h"
#include "Staff.h"
#include "SmallHpPotion.h"
#include "MedHpPotion.h"
#include "LargeHpPotion.h"

#include <iostream>
#include <vector>
#include <random>
#include <conio.h>

using namespace std;

class Rand
{
private:
	// Metody
public:
	Rand();														// Konstruktor
	void RandItem(int zone, Inventory &inv,Player *player);		// Tworzenie losowego przedmiotu
	Item* Create(Inventory &inv);								// Tworzenie przedmiotu
	~Rand();													// Destruktor
};	

