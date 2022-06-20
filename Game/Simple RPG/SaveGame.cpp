#include "SaveGame.h"

SaveGame::SaveGame()
{
	file_name = "";
	cout << "Nazwij swój zapis" << endl;
	cin >> file_name;
	ofstream file(file_name);
	file.close();
}

void SaveGame::CreateSaveFile(int zone, vector<vector<int>> map, Player* p, 
	Inventory &inv, Shop &shop)
{

	fstream file;

	file.open(file_name, ios::out | ios::app);
	{
		if (file.good() == true)
		{
			file << zone << endl;							// Strefa

			file << map.size() << endl;						// Liczba wierszy mapy

			file << map[0].size() << endl;					// Liczba pomieszczeñ / wiersz


			for (int i = 0; i < map.size(); i++)			// Mapa
			{
				for (int j = 0; j < map[i].size(); j++)
				{
					file << map[i][j] << endl;
				}
			}
														// Statystyki gracza
			file << p->name << endl << p->_class << endl << p->strength << endl << p->maxhp
				<< endl << p->hp << endl << p->defence << endl << p->magic << endl << p->maxequipment
				<< endl << p->equipment << endl << p->level << endl << p->maxexp << endl << p->exp
				<< endl << p->gold << endl << p->actions << endl;

			for (int i = 0; i < 3; i++)					// Liczba mikstur zdrowia w ekwipunku gracza
			{
				file << inv.items[i]->count << endl;
			}
			for (int i = 3; i < inv.items.size(); i++)	// Przedmioty Gracza
			{
				file << inv.items[i]->weapon << endl << inv.items[i]->armor << endl << inv.items[i]->class_ 
					<< endl << inv.items[i]->level << endl;
			}
														// Wyekwipowane przedmioty
			file << inv.armorEquiped << endl << inv.posOfArmor << endl << inv.weaponEquiped 
				<< endl << inv.posOfWeapon << endl;

			for (int i = 0; i < 3; i++)					// Liczba mikstur zdrowia w sklepie
			{
				file << shop.store[i]->count << endl;
			}

			file << shop.store.size() - 3 << endl;				// Liczba przedmiotów w sklepie

			for (int i = 3; i < shop.store.size(); i++)	// Przedmioty w sklepie
			{
				file << shop.store[i]->weapon << endl << shop.store[i]->armor << endl << shop.store[i]->class_
					<< endl << shop.store[i]->level << endl;
			}

			file.close();

		}
	}
}

SaveGame::~SaveGame()
{

}