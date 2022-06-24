#pragma once

#include "SaveGame.h"
#include "Shop.h"
#include "PlayerEdit.h"
#include "Commands.h"
#include "LevelGen.h"
#include "FightSystem.h"
#include "Rand.h"
#include "Player.h"
#include "Inventory.h"

#include <vector>
#include <iostream>
#include <conio.h>

#define ESC 27
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

class Movement
{
private:
	int wybor;
	int x, y;					// Przechowuj¹ pozycjê gracza
	int originalValue;			// Zapis wartoœci pola, na której stan¹³ gracz
	bool can_go;				// Warunek na ruch gracza
	bool show_up;				// Warunek na przesuniêcie siê 1 pole w górê
	bool show_left;				// Warunek na przesuniêcie siê 1 pole w lewo
	bool show_right;			// Warunek na przesuniêcie siê 1 pole w prawo
	bool show_down;				// Warunek na przesuniêcie siê 1 pole w dó³

public:
	static bool exit;			// Warunek wyjœcia z gry
	static int bossRoom;		// Dziêki temu aktywowany jest ostatni potwór
	int room;					// Pokój, do którego wchodzi gracz
	long int zone;				// Piêtro lochów
	// Metody
	friend class LevelGen;
	friend class FightSystem;
	friend class Player;
	Movement();																// Konstruktor
	void MovementCheck(LevelGen& level);
	void Action(FightSystem& fight, LevelGen& level, Player *player, Inventory &inventory,
		Commands &commands, Shop &shop);									// Rozpatrywanie wyborów dokonanych przez gracza
	bool ExitAsk();															// Zapytanie o zejœcie na ni¿sze piêtro lochów
	void RoomCheck(vector<vector<int>> &level,int zone, int room, FightSystem& fight, 
		Inventory &inventory, Item *wsk, Player* player, Shop &shop);		// Zdarzenia do rozpatrzenia po ruchu gracza
	~Movement();															// Destruktor
};

