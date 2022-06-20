#ifndef ENEMY_H
#define ENEMY_H

using namespace std;

#include"Player.h"

#include <string>
#include <iostream>

class Enemy
{
protected:

	// atrybuty
	string name;		// Nazwa przeciwnika
	int strength;		// Wartoœæ si³y
	int maxhp;			// Maksymalna wartoœæ punktów zdrowia
	int hp;				// Aktualna wartoœæ punktów zdrowia
	int defence;		// Wartoœæ obrony
	int magic;			// Wartoœæ magii
	int level;			// Wartoœæ aktualnego poziomu przeciwnika
	int exp;			// Iloœæ doœwiadczenia otrzymywanego po pokonaniu przeciwnika
	int damage;			// Wartoœæ obra¿eñ zadawanych przez przeciwnika
	int action;			// Liczba akcji na turê

	// metody
public:
	static int id;
	friend class FightSystem;
	void Stats();						// Wyœwietlenie statystyk
	virtual void Ability() = 0;			// Wywoa³nie specjalnej umiejêtnoœci
	virtual void DestroyEnemy() = 0;	// Wywo³anie destruktora

};

#endif