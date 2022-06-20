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
	int strength;		// Warto�� si�y
	int maxhp;			// Maksymalna warto�� punkt�w zdrowia
	int hp;				// Aktualna warto�� punkt�w zdrowia
	int defence;		// Warto�� obrony
	int magic;			// Warto�� magii
	int level;			// Warto�� aktualnego poziomu przeciwnika
	int exp;			// Ilo�� do�wiadczenia otrzymywanego po pokonaniu przeciwnika
	int damage;			// Warto�� obra�e� zadawanych przez przeciwnika
	int action;			// Liczba akcji na tur�

	// metody
public:
	static int id;
	friend class FightSystem;
	void Stats();						// Wy�wietlenie statystyk
	virtual void Ability() = 0;			// Wywoa�nie specjalnej umiej�tno�ci
	virtual void DestroyEnemy() = 0;	// Wywo�anie destruktora

};

#endif