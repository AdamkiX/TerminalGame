#include "LoadGame.h"

LoadGame::LoadGame()
{
	iNum = 0;
	s = "";
	temp_line = 1;
	line = 1;
	file_name = "";
	cout << "Podaj œcie¿kê zapisu" << endl;
	cin >> file_name;
}

void LoadGame::LoadSaveFile()
{
	fstream file;
	s;
	file.open(file_name, ios::in);
	if (file.good() == true)
	{

	}
	else
	{
		cout << "Plik nie istnieje" << endl;
		system("pause");
		system(0);
	}
	file.close();
}

LevelGen LoadGame::LoadLevel()
{
	int i = 0, j = 0;
	fstream file;
	LevelGen gen;
	int ySize = 0, xSize = 0 ,Value = 0;
	vector<int> temp;
	file.open(file_name, ios::in);
	if (file.good() == true)
	{
		while (getline(file, s))
		{
			if (line == 1)
			{
				gen.zone = stoi(s);
				line++;
			}
			else if (line == 2)
			{
				ySize = stoi(s);
				line++;
			}
			else if (line == 3)
			{
				xSize = stoi(s);
				line++;
			}
			else
			{
				if (line > xSize * ySize + 3)
				{
					temp_line = line;
					line = 0;
					break;
				}
				else
				{
					temp.push_back(stoi(s));		// xSize razy
					line++;
				}
			}
		}
	}
	else
	{
		cout << "Plik nie istnieje" << endl;
		system("pause");
		exit(0);
	}
	int k = 0;
	for (int i = 0; i < ySize; i++)
	{
		for (int j = 0; j < xSize; j++)
		{
			gen.tilesX.push_back(temp[k]);
			k++;
		}
		gen.tilesY.push_back(gen.tilesX);
		gen.tilesX.clear();		gen.tilesX.shrink_to_fit();
	}

	file.close();
	return gen;
}
	

Player* LoadGame::LoadPlayerStats()
{
	fstream file;
	Player* p = 0;
	string  name, class_;

	name = s;

	file.open(file_name, ios::in);
	if (file.good() == true)
	{
		while (getline(file, s))
		{
			if (line < temp_line)
			{
				line++;
			}
			else if (temp_line == line)
			{
				class_ = s;
				line++;
			}
			else if (temp_line + 1 == line)
			{

				if (class_ == "Wojownik")
				{
					p = new Warior(1);
				}
				else if (class_ == "Mag")
				{
					p = new Mage(1);
				}
				else
				{
					p = new Rogue(1);
				}
				line++;
				p->name = name;
				p->strength = stoi(s);
			}
			else if (temp_line + 2 == line)
			{
				p->maxhp = stoi(s);
				line++;
			}
			else if (temp_line + 3 == line)
			{
				p->hp = stoi(s);
				line++;
			}
			else if (temp_line + 4 == line)
			{
				p->defence = stoi(s);
				line++;
			}
			else if (temp_line + 5 == line)
			{
				p->magic = stoi(s);
				line++;
			}
			else if (temp_line + 6 == line)
			{
				p->maxequipment = stoi(s);
				line++;
			}
			else if (temp_line + 7 == line)
			{
				p->equipment = stoi(s);
				iNum = p->equipment;
				line++;
			}
			else if (temp_line + 8 == line)
			{
				p->level = stoi(s);
				line++;
			}
			else if (temp_line + 9 == line)
			{
				p->maxexp = stoi(s);
				line++;
			}
			else if (temp_line + 10 == line)
			{
				p->exp = stoi(s);
				line++;
			}
			else if (temp_line + 11 == line)
			{
				p->gold = stoi(s);
				line++;
			}
			else if (temp_line + 12 == line)
			{
				p->actions = stoi(s);
				line++;
				temp_line = line;
				line = 0;
				break;
			}

		}
	}
	file.close();
	return p;
}

Inventory LoadGame::LoadInventory()
{
	fstream file;
	Inventory inv;
	string class_;
	int i = 0, k = 1, arm = 0, wea = 0, lv = 0;

	Item* wskI = 0;

	wskI = new SmallHpPotion;
	temp.push_back(wskI);
	wskI= new MedHpPotion;
	temp.push_back(wskI);
	wskI = new LargeHpPotion;
	temp.push_back(wskI);


	file.open(file_name, ios::in);

	if (file.good() == true)
	{
		while (getline(file, s))
		{
			if (line < temp_line)
			{
				line++;
			}
			else if (line < (temp_line + 3))
			{
				temp[i]->count = stoi(s);
				i++;
				line++;
			}
			else if (line < (temp_line + 3 + (iNum * 4)))
			{
				switch (k)
				{
				case 1:
				{
					wea = stoi(s);
					k++;
					line++;
					break;
				}
				case 2:
				{
					arm = stoi(s);
					k++;
					line++;
					break;
				}
				case 3:
				{
					class_ = s;
					k++;
					line++;
					break;
				}
				case 4:
				{
					lv = stoi(s);
					if (arm == 1)
					{
						if (class_ == "Wojownik")
						{
							wskI = new Chainmail(lv, Item::id);
						}
						else if (class_ == "Mag")
						{
							wskI = new Robe(lv, Item::id);
						}
						else
						{
							wskI = new Cloak(lv, Item::id);
						}
					}
					else
					{
						if (class_ == "Wojownik")
						{
							wskI = new Sword(lv, Item::id);
						}
						else if (class_ == "Mag")
						{
							wskI = new Staff(lv, Item::id);
						}
						else
						{
							wskI = new Dagger(lv, Item::id);
						}
					}
					temp.push_back(wskI);
					line++;
					k = 1;
					break;
				}
				}
			}
			else if (line < (temp_line + 3 + (iNum * 4)) + 1)
			{
				inv.armorEquiped = stoi(s);
				line++;
			}
			else if (line < (temp_line + 3 + (iNum * 4)) + 2)
			{
				inv.posOfArmor = stoi(s);
				line++;
			}
			else if (line < (temp_line + 3 + (iNum * 4)) + 3)
			{
				inv.weaponEquiped = stoi(s);
				line++;
			}
			else if (line < (temp_line + 3 + (iNum * 4)) + 4)
			{
				inv.posOfWeapon = stoi(s);
				temp_line = line;
				line = 0;
				break;
			}
		}
	}
	file.close();
	return inv;
}

vector<Item*> LoadGame::LoadItems()
{
	return temp;
}

Shop LoadGame::LoadShop()
{
	fstream file;
	Shop shop;
	string class_;
	bool a = false, b = false;
	int item = 0, lv = 0, wea = 0, arm = 0, stash = 0;;
	int i = 0, k = 1;

	Item* wskI = 0;

	wskI = new SmallHpPotion;
	shop.store.push_back(wskI);
	wskI = new MedHpPotion;
	shop.store.push_back(wskI);
	wskI = new LargeHpPotion;
	shop.store.push_back(wskI);

	file.open(file_name, ios::in);

	if (file.good() == true)
	{
		while (getline(file, s))
		{
			if (line < temp_line + 1)
			{
				line++;
			}
			else if (line < (temp_line + 4))
			{
				shop.store[i]->count = stoi(s);
				i++;
				line++;
			}
			else if (line < (temp_line + 5))
			{
				stash = stoi(s);
				line++;
			}
			else if (line < (temp_line + 5 + (stash * 4)))
			{
				switch (k)
				{
				case 1:
				{
					wea = stoi(s);
					k++;
					line++;
					break;
				}
				case 2:
				{
					arm = stoi(s);
					k++;
					line++;
					break;
				}
				case 3:
				{
					class_ = s;
					k++;
					line++;
					cout << class_ << endl;
					break;
				}
				case 4:
				{
					lv = stoi(s);
					if (arm == 1)
					{
						if (class_ == "Wojownik")
						{
							wskI = new Chainmail(lv, Item::id);
						}
						else if (class_ == "Mag")
						{
							wskI = new Robe(lv, Item::id);
						}
						else
						{
							wskI = new Cloak(lv, Item::id);
						}
					}
					else
					{
						if (class_ == "Wojownik")
						{
							wskI = new Sword(lv, Item::id);
						}
						else if (class_ == "Mag")
						{
							wskI = new Staff(lv, Item::id);
						}
						else
						{
							wskI = new Dagger(lv, Item::id);
						}
					}
					temp.push_back(wskI);
					line++;
					k = 1;
					break;
				}
				}
			}
		}

		return shop;
	}
}

LoadGame::~LoadGame()
{
	
}