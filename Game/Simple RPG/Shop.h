#pragma once

#include "Player.h"
#include "Inventory.h"
#include "Rand.h"

class Shop
{
	vector<Item*> store;				// Przedmioty w sklepie
	vector<Item*>::iterator it;			// iterator wektora
	int ammOfGen;						// Iloœæ generowanych przedmiotów

public:
	friend class SaveGame;
	friend class LoadGame;
	Shop(int zone);												// Konstruktor
	Shop();														// Konstruktor
	void AddItem(Item* item);									// Dodanie przedmiotu do sklepu
	void GenerateShop(int zone);								// Generowanie losowego sklepu
	void ShopMenu(Player* player, Inventory& inv);				// Menu sklepu
	void ShopStorage(Player* player,Inventory& inv);			// Zaopatrzebnie sklepu
	void BuyItem(Player* player, Inventory &inv, int choice);	// Zakup przedmiotu
	void PlayerStorage(Player *player, Inventory& inv);			// Ekwipunek gracza
	void SellItem(Player* player, Inventory& inv, int choice);	// Sprzeda¿ przedmiotu z ekwipunku gracza
	void ShowShop();											// Pokazanie zawartoœci sklepu
	bool CanAfford(Player *player, int cost);					// Srawdza, czy staæ gracza na zakup
	int InputCheck();											// Sprawdza poprawnoœæ wpisywanych danych
	~Shop();													// Destruktor
};

