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
	int x, y;					// Przechowuj� pozycj� gracza
	int originalValue;			// Zapis warto�ci pola, na kt�rej stan�� gracz
	bool can_go;				// Warunek na ruch gracza
	bool show_up;				// Warunek na przesuni�cie si� 1 pole w g�r�
	bool show_left;				// Warunek na przesuni�cie si� 1 pole w lewo
	bool show_right;			// Warunek na przesuni�cie si� 1 pole w prawo
	bool show_down;				// Warunek na przesuni�cie si� 1 pole w d�

public:
	static bool exit;			// Warunek wyj�cia z gry
	static int bossRoom;		// Dzi�ki temu aktywowany jest ostatni potw�r
	int room;					// Pok�j, do kt�rego wchodzi gracz
	long int zone;				// Pi�tro loch�w
	// Metody
	friend class LevelGen;
	friend class FightSystem;
	friend class Player;
	Movement();																// Konstruktor
	void MovementCheck(LevelGen& level);
	void Action(FightSystem& fight, LevelGen& level, Player *player, Inventory &inventory,
		Commands &commands, Shop &shop);									// Rozpatrywanie wybor�w dokonanych przez gracza
	bool ExitAsk();															// Zapytanie o zej�cie na ni�sze pi�tro loch�w
	void RoomCheck(vector<vector<int>> &level,int zone, int room, FightSystem& fight, 
		Inventory &inventory, Item *wsk, Player* player, Shop &shop);		// Zdarzenia do rozpatrzenia po ruchu gracza
	~Movement();															// Destruktor
};

