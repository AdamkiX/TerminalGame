#pragma once

#include "Player.h"

#include <iostream>
#include <string>

using namespace std;

class Item
{
protected:
	bool weapon;						// Typ przedmiotu
	bool armor;							// Typ przedmiotu
	int level;							// Poziom przedmiotu
	string name;						// Nazwa przedmiotu
	string class_;						// Klasa przedmiotu
	int defence;						// Bonus do obrony
	int hp;								// Bonus do zdrowia
	int strength;						// Bosnus do si³y
	int magic;							// Bonus do magii
	int count;							// Iloœæ przedmiotu (mikstury zdrowia)
	int goldValue;						// Wartoœæ w z³ocie przedmiotu
public:
	static int id;
	virtual void Stats();				// Wyœwietla statystyki przedmiotu
	virtual void AddPots(int i);		// Zwiêksza licznik mikstur o 1
	virtual void DestroyItem();			// Wywo³uje destruktor
	friend class Inventory;
	friend class Rand;
	friend class Shop;
	friend class SaveGame;
	friend class LoadGame;
};

