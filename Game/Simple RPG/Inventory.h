#pragma once

#include "Player.h"
#include "Item.h"

#include <conio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Inventory
{
private:
	int posOfArmor;							// Przechowuje, pozycj� w wektorze dla zbroji
	int posOfWeapon;						// Przechowuje, pozycj� w wektorze dla broni
	bool armorEquiped;						// Czy zbroja jest wyekwipowana
	bool weaponEquiped;						// Czy bro� jest wyekwipowana
	Item* item;								// Wska�nik na przedmiot
	vector<Item*> items;					// Wektor przedmiot�w / ekwipunek gracza
	vector<Item*>::iterator it;				// Wska�nik na wektor
public:
	friend class Rand;
	friend class Shop;
	friend class SaveGame;
	friend class LoadGame;
	Inventory();									// Konstruktor
	void AddItem(Item* item);						// Dodawanie przedmiotu do ekwipunku
	void AddItem(Item *item, Player *p);			// Dodawanie przedmiotu do ekwipunku 
	void AddPotHolder(Item* item);					// Dodawanie slotu na mikstury zdrowia
	void AddStartPots();							// Dodawanie mikstur
	void DestroyItem(Player *p);					// Niszczenie przedmiotu z ekwipunku
	void EquipCheck(int what, Player *player);		// Sprawdza, czy mo�na ekwipowa� przedmiot
	void Equip(Player* player);						// Ekwipowanie przedmiotu
	void EquipArmor(int what, Player* player);		// Ekwipowanie konkretnej zbroji
	void EquipWeapon(int what, Player* player);		// Ekwipowanie konkretnej broni
	void Unequip(Player *p);						// Zdejmowanie przedmiotu z postaci
	void UnequipArmor(Player* player);				// Zdejmowanie konkretnej zbroji z postaci
	void UnequipWeapon(Player* player);				// Zdejmowanie konkretnej broni z postaci
	void ShowInvMenu(Player* player);				// Pokazuje menu ekwipunku
	int InputCheck();								// Sprawdza poprawno�� wpisywanych danych
	void ShowInv();									// Pokazuje przedmioty w ekwipunku
	void ShowItemStats();							// Pokazuje statystyki konkretnego przedmiotu
	void LoopAsk();									// Zap�tla zapytanie o pokazanie statystyk jakiego� przedmiotu
	void CheckItem();								// Prosi gracza o podanie przedmiotu, kt�ry chce sprawdzi�
	void UseHpPot(Player* player);					// U�ycie mikstury regeneruj�cej zdrowie
	void CheckHpPots(int choice, Player* player);	// Sprawdza, czy gracz posiada mikstury danego typu
	void EreaseItem(int what);						// Odpowiada za usuni�cie pozycji w wektorze przedmiot�w
	~Inventory();									// Destruktor
};

