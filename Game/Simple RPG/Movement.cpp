#include "Movement.h"


Movement::Movement()
{
	originalValue = 1;
	zone = 0; x = 0; y = 0;
	room = 0;
	wybor = 0;
	can_go = false;
	show_up = false;
	show_left = false;
	show_right = false;
	show_down = false;
}

void Movement::MovementCheck(LevelGen& level)
{
	zone = level.zone;
	if (Commands::devMode == true)
	{
		for (int i = 0; i < level.tilesY.size(); i++)
		{
			for (int j = 0; j < level.tilesY[i].size(); j++)
			{
				cout << level.tilesY[i][j] << " ";
			}
			cout << endl;
		}
	}


	for (int i = 0; i < level.tilesY.size(); i++)
	{
		for (int j = 0; j < level.tilesY[i].size(); j++)
		{
			if (level.tilesY[i][j] == 7)
			{
				y = i;
				x = j;
				if (level.tilesY[y + 1][x] != 0)
				{
					show_up = true;
				}
				if (level.tilesY[y - 1][x] != 0)
				{
					show_down = true;
				}
				if (level.tilesY[y][x+1] != 0)
				{
					show_right = true;
				}
				if (level.tilesY[y][x-1] != 0)
				{
					show_left = true;
				}
			}
		}
	}


}


void Movement::RoomCheck(vector<vector<int>> &l, int z, int r, FightSystem& f, 
	Inventory &inv, Item *wsk, Player *p, Shop &s)
{
	switch (r)
	{
	case 1:		// Puste pole
	{
		originalValue = 1;
		break;
	}
	case 2:		// Pole z przeciwnikiem/ami
	{
		system("cls");
		f.fighting = true;
		room = 1;
		originalValue = 1;
		break;
	}
	case 3:		// Pole ze skarbem
	{
		if (p->equipment <= p->maxequipment)
		{
			Rand item;
			item.RandItem(z, inv, p);
			originalValue = 1;
		}
		else
		{
			originalValue = 3;
			system("cls");
			cout << "Znalaz�e� przedmiot, lecz nie masz na niego miejsca." << endl;
			Sleep(1000);
		}

		break;
	}
	case 4:		// Pole ze sklepem
	{
		originalValue = 4;
		system("cls");
		s.ShopMenu(p, inv);
		break;
	}
	case 5:		// Pole z wyj�ciem
	{
		break;
	}
	case 6:		// Pok�j z Bossem gry
	{
		Movement::bossRoom = 6;
		system("cls");
		f.fighting = true;
		room = 1;
		originalValue = 1;
		if (f.fighting == false)
		{
			Movement::bossRoom = 1;
		}
		break;
	}

	//DevMode
	case 7:		// Tworzenie przedmiotu
	{
		Rand item;
		wsk = item.Create(inv);
		if (wsk != 0)
		{
			inv.AddItem(wsk,p);
		}
		break;
	}
	case 8:		// Wywo�ywanie walki
	{
		break;
	}
	case 9:		// Przej�cia na nast�pny poziom
	{
		l[y + 1][x] = 5;
		l[y - 1][x] = 5;
		l[y][x + 1] = 5;
		l[y][x - 1] = 5;
		break;
	}
	case 10:	// Edycja parametr�w gracza
	{
		PlayerEdit e(p);
		break;
	}
	}

}

void Movement::Action(FightSystem& f, LevelGen &l, Player *p, Inventory &inv, Commands &c, Shop &s)
{
	bool sellected = false;

	if (f.fighting == false)
	{

		
		do
		{
			cout << "Jeste� poza walk�. Mo�esz swobodnie zwiedza� lochy." << endl;			
			cout << "Je�li chcesz podejrze� statystyki wci�nij: s" << endl;
			cout << "Je�li chcesz podejrze� przedmioty wci�nij: p" << endl;
			cout << "Je�li chcesz zapisa� gr� wci�nij: z" << endl;
			cout << "Je�li chcesz wyj�� z gry wci�nij: ESC" << endl;

		wybor = _getch();			

			switch (wybor)
			{
			case KEY_DOWN:
			{
				if (show_up == true)
				{
					room = l.tilesY[y + 1][x];
					if (room == 5)
					{
						cout << "Znalaz�e� wyj�cie" << endl;
					}
					else
					{
						l.tilesY[y][x] = originalValue;
						l.tilesY[y + 1][x] = 7;
					}
					sellected = true;
				}
				else
				{
					system("cls");
					l.DrawMap();
				}

				break;
			}
			case KEY_UP:
			{
				if (show_down == true)
				{
					room = l.tilesY[y - 1][x];
					l.tilesY[y][x] = originalValue;
					l.tilesY[y - 1][x] = 7;
					sellected = true;
				}
				else
				{
					system("cls");
					l.DrawMap();
				}
				break;
			}
			case KEY_RIGHT:
			{
				if (show_right == true)
				{
					room = l.tilesY[y][x + 1];
					l.tilesY[y][x] = originalValue;
					l.tilesY[y][x + 1] = 7;
					sellected = true;
				}
				else
				{
					system("cls");
					l.DrawMap();
				}

				break;
			}
			case KEY_LEFT:
			{
				if (show_left == true)
				{

					room = l.tilesY[y][x - 1];
					if (room == 5)
					{
						cout << "Znalaz�e� wyj�cie" << endl;
					}
					else
					{
						l.tilesY[y][x] = originalValue;
						l.tilesY[y][x - 1] = 7;
					}
					sellected = true;

				}
				else
				{
					system("cls");
					l.DrawMap();
				}
				break;
			}
			case 's':
			{
				system("cls");
				p->Stats();
				l.DrawMap();
				room = 1;
				break;
			}
			case 'p':
			{
				system("cls");
				inv.ShowInvMenu(p);
				system("cls");
				l.DrawMap();
				break;
			}
			case 'z':
			{
				string choice;
				system("cls");
				cout << "Czy na pewno chcesz zapisa� gr�?" << endl;
				cout << "	Tak		Nie" << endl;

				cin >> choice;

				if (choice == "Tak" or choice == "tak" or choice == "t")
				{
					SaveGame save;
					save.CreateSaveFile(l.zone, l.tilesY, p, inv, s);
					save.~SaveGame();
					cout << "Gra zosta�a zapisana!" << endl;
				}
				system("cls");
				l.DrawMap();

				break;
			}
			case '`':
			{
				room = (c.DevMode()+6);
				if (room == 11)
				{
					break;
				}
				else
				{
					sellected = true;
				}
				break;

			}
			case ESC:
			{
				string yn;
				system("cls");
				cout << "Czy na pewno chcesz wyj�� z gry?" << endl;
				cout << "	Tak		Nie" << endl;
				cin >> yn;
				if (yn == "Tak" or yn == "tak" or yn == "t")
				{
					exit(0);
				}
				system("cls");
				l.DrawMap();
				break;
			}
			default:
			{
				system("cls");
				l.DrawMap();
				break;
			}
			}
		} while (sellected == false);
		show_up = false;
		show_down = false;
		show_right = false;
		show_left = false;
	}

}

bool Movement::ExitAsk()
{
	string yn = "";
	bool choice = false, ok = false;
	do
	{
		cout << "Czy chcesz zej�� na ni�sze pi�tro?" << endl;
		cout << "	Tak						Nie" << endl;
		cin >> yn;
		if (yn == "Tak" or yn == "tak")
		{
			choice = true;
			ok = true;
		}
		else if (yn == "Nie" or yn == "nie")
		{
			choice = false;
			ok = true;
		}
		system("cls");
	} while (ok == false);
	return choice;
}

Movement::~Movement()
{

}