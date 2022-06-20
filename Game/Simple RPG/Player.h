#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>


using namespace std;

class Player
{
protected:
	// atrybuty
	string name;		// Nazwa postaci, kt�r� gracz podaje
	string _class;		// Klasa postaci
	int strength;		// Warto�� si�y
	int maxhp;			// Maksymalna warto�� punkt�w zdrowia
	int hp;				// Aktualna warto�� punkt�w zdrowia
	int defence;		// Warto�� obrony
	int magic;			// Warto�� magii
	int maxequipment;	// Maksymalna �adowno�� ekwipunku
	int equipment;		// �adowno�� ekwipuknu
	int level;			// Warto�� aktualnego poziomu postaci
	int maxexp;			// Warto�� do�wiadczenia jak� posta� musi uzysk�� by zwi�kszy� sw�j poziom
	int exp;			// Warto�� aktualnego do�wiadczenia
	int gold;			// Ilo�� z�ota posiadanego przez gracza
	int actions;		// Liczba akcji ile mo�e gracz wykona� w turze

public:
	friend class Inventory;
	friend class FightSystem;
	friend class Item;
	friend class PlayerEdit;
	friend class Movement;
	friend class SaveGame;
	friend class LoadGame;
	void Naming(int c);						// Nazwanie postaci
	void Stats();							// Pokazanie statystyk postaci
	int GetMoney();							// Przekazanie warto�ci z�ota postacii
	void ChangeMoney(int ammount);			// Zmiana warto�ci z�ota postacii
	void EquipmentUpdate(int i);			// Zmiana warto�ci �adowno�ci ekwipunku o 1
	virtual void Ability(int i) = 0;		// Umiej�tno�� specjalna
	virtual void LevelUp(int i) = 0;		// Podniesienie poziomu postaci o 1
	virtual void DestroyPlayer() = 0;		// Wywo�anie destruktora
};

#endif // !PLAYER_H