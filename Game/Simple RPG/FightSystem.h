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
	int Pturns;									// Przechowuje warto�ci akcji gracza na tur�
	int turn;									// Przechowuj� warto�ci tur
	bool fighting;								// Warunek na rozpocz�cie walki
	vector<Enemy*> enemys;						// Wektor przeciwnik�w
	vector<Enemy*>::iterator it;				// Iterator wektora

public:
	int zone;
	friend class Movement;
	FightSystem();													// Konstruktor
	bool Fight(Player* player, Inventory& inv);						// Odpowiada za walk�
	bool FightCheck(Player* player, Inventory& inv, int zone);		// Sprawdza, czy rozpocz�� walk�
	int RandEnemyNum();												// Losowanie przeciwnik�w
	void GenerateEnemy();											// Generowanie przeciwnik�w
	void PlayerTurn(Player * player, Inventory& inv);				// Tura gracza
	void PlayerAttack(Player * player);								// Opcja ataku
	void EveryoneStats(Player* player);								// Wy�wietlenie statystyk
	void EnemyTurn(int enemy, Player* p);							// Tura przeciwnika
	void EnemyDeathCheck(int enemy,Player *p);						// Sprawdza, czy przeciwnik pokonany
	~FightSystem();													// Destruktor
};

