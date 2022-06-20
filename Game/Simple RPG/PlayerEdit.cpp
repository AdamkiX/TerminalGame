#include "PlayerEdit.h"

PlayerEdit::PlayerEdit(Player* p)
{
	bool exit = false;
	cout << "Witaj w edytorze postaci" << endl;
	do
	{
		int choice;
		cout << "Wybierz jaki parametr chcesz edytowa�, lub wyjd�" << endl;
		cout << "1. Poziom" << endl << "2. Zdrowie" << endl << "3. Maksymalne zdrowie" << endl
			<< "4. Obrona" << endl << "5. Magia" << endl << "6. Si�a" << endl 
			<< "7. Pojemno�� ekwipunku" << endl << "8. Maksymalna pojemno�� ekwipunku" << endl
			<< "9. Exit" << endl;
			 

		choice = _getch();

		switch (choice)
		{
		case '1':
		{
			int lv;
			cout << "Wpisz jaki poziom ma mie� posta�" << endl;
			cin >> lv;
			p->LevelUp(lv);
			break;
		}
		case '2':
		{
			int hp;
			cout << "Wpisz jakie zdrowie ma mie� posta�" << endl;
			cin >> hp;
			p->hp = hp;
			break;
		}
		case '3':
		{
			int maxhp;
			cout << "Wpisz jakie maksymalne zdrowie ma mie� posta�" << endl;
			cin >> maxhp;
			p->maxhp;
			break;
		}
		case '4':
		{
			int def;
			cout << "Wpisz jak� obron� ma mie� posta�" << endl;
			cin >> def;
			p->defence = def;
			break;
		}
		case '5':
		{
			int mag;
			cout << "Wpisz jak� magi� ma mie� posta�" << endl;
			cin >> mag;
			p->magic = mag;
			break;
		}
		case '6':
		{
			int str;
			cout << "Wpisz jak� si�� ma mie� posta�" << endl;
			cin >> str;
			p->strength = str;
			break;
		}
		case '7':
		{
			int eq;
			cout << "Wpisz jak� pojemno�� ekwipunku ma mie� posta�" << endl;
			cin >> eq;
			p->equipment = eq;
			break;
		}
		case '8':
		{
			int maxeq;
			cout << "Wpisz jak� si�� ma mie� posta�" << endl;
			cin >> maxeq;
			p->maxequipment = maxeq;
			break;
		}

		case '9':
		{
			exit = true;
			break;
		}
		}
		system("cls");
	} while (exit == false);

}
