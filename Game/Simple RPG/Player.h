#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>


using namespace std;

class Player
{
protected:
	// atrybuty
	string name;		// Nazwa postaci, któr¹ gracz podaje
	string _class;		// Klasa postaci
	int strength;		// Wartoœæ si³y
	int maxhp;			// Maksymalna wartoœæ punktów zdrowia
	int hp;				// Aktualna wartoœæ punktów zdrowia
	int defence;		// Wartoœæ obrony
	int magic;			// Wartoœæ magii
	int maxequipment;	// Maksymalna ³adownoœæ ekwipunku
	int equipment;		// £adownoœæ ekwipuknu
	int level;			// Wartoœæ aktualnego poziomu postaci
	int maxexp;			// Wartoœæ doœwiadczenia jak¹ postaæ musi uzysk¹æ by zwiêkszyæ swój poziom
	int exp;			// Wartoœæ aktualnego doœwiadczenia
	int gold;			// Iloœæ z³ota posiadanego przez gracza
	int actions;		// Liczba akcji ile mo¿e gracz wykonaæ w turze

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
	int GetMoney();							// Przekazanie wartoœci z³ota postacii
	void ChangeMoney(int ammount);			// Zmiana wartoœci z³ota postacii
	void EquipmentUpdate(int i);			// Zmiana wartoœci ³adownoœci ekwipunku o 1
	virtual void Ability(int i) = 0;		// Umiejêtnoœæ specjalna
	virtual void LevelUp(int i) = 0;		// Podniesienie poziomu postaci o 1
	virtual void DestroyPlayer() = 0;		// Wywo³anie destruktora
};

#endif // !PLAYER_H