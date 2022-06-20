#pragma once

#include "Shop.h"
#include "Player.h"
#include "Warior.h"
#include "Mage.h"
#include "Rogue.h"
#include "LevelGen.h"
#include "Inventory.h"
#include "Shop.h"
#include "Chainmail.h"
#include "Cloak.h"
#include "Robe.h"
#include "Dagger.h"
#include "Staff.h"
#include "Sword.h"
#include "SmallHpPotion.h"
#include "MedHpPotion.h"
#include "LargeHpPotion.h"

#include <fstream>
#include <sstream>

class LoadGame
{
	int line, temp_line, iNum;
	string s, file_name;
public:
	vector<Item*> temp;
	LoadGame();						// Konstruktor
	void LoadSaveFile();			// Za³adowanie pliku z zapisem gry
	vector<Item*> LoadItems();		// Za³adowanie przedmiotów gracza
	LevelGen LoadLevel();			// Za³adowanie poziomu
	Player* LoadPlayerStats();		// Za³adowanie postaci
	Inventory LoadInventory();		// Za³adowanie ewkipunku gracza
	Shop LoadShop();				// Za³adowanie sklepu
	~LoadGame();					// Destruktor
};

