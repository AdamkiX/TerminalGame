#pragma once

#include "Inventory.h"
#include "Player.h"
#include "Boss.h"
#include "GoblinMage.h"
#include "GoblinRogue.h"
#include "OrcWarior.h"
#include "OrcMage.h"

#include <conio.h>
#include <random>
#include <vector>
#include <iostream>
#include <Windows.h>


class FightSystem
{
private:
	bool won = false, end = false;				// Warunki na koniec gry
	int Pturns;									// Przechowuje wartoœci akcji gracza na turê
	int turn;									// Przechowujê wartoœci tur
	bool fighting;								// Warunek na rozpoczêcie walki
	vector<Enemy*> enemys;						// Wektor przeciwników
	vector<Enemy*>::iterator it;				// Iterator wektora

public:
	int zone;
	friend class Movement;
	FightSystem();													// Konstruktor
	bool Fight(Player* player, Inventory& inv);						// Odpowiada za walkê
	bool FightCheck(Player* player, Inventory& inv, int zone);		// Sprawdza, czy rozpocz¹æ walkê
	int RandEnemyNum();												// Losowanie przeciwników
	void GenerateEnemy();											// Generowanie przeciwników
	void PlayerTurn(Player * player, Inventory& inv);				// Tura gracza
	void PlayerAttack(Player * player);								// Opcja ataku
	void EveryoneStats(Player* player);								// Wyœwietlenie statystyk
	void EnemyTurn(int enemy, Player* p);							// Tura przeciwnika
	void EnemyDeathCheck(int enemy,Player *p);						// Sprawdza, czy przeciwnik pokonany
	~FightSystem();													// Destruktor
};

