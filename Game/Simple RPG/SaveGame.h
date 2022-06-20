#pragma once

#include "Player.h"
#include "LevelGen.h"
#include "Inventory.h"
#include "Shop.h"

#include <fstream>



class SaveGame
{
	string file_name;

public:
	SaveGame();								// Konstruktor
	void CreateSaveFile(int zone,vector<vector<int>> map, Player *p, 
		Inventory &inv, Shop &shop);		// Zapis do pliku postêpu w grze
	~SaveGame();							// Destruktor
};

