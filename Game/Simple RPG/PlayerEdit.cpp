#include "PlayerEdit.h"

PlayerEdit::PlayerEdit(Player* p)
{
	bool exit = false;
	cout << "Witaj w edytorze postaci" << endl;
	do
	{
		int choice;
		cout << "Wybierz jaki parametr chcesz edytowaæ, lub wyjdŸ" << endl;
		cout << "1. Poziom" << endl << "2. Zdrowie" << endl << "3. Maksymalne zdrowie" << endl
			<< "4. Obrona" << endl << "5. Magia" << endl << "6. Si³a" << endl 
			<< "7. Pojemnoœæ ekwipunku" << endl << "8. Maksymalna pojemnoœæ ekwipunku" << endl
			<< "9. Exit" << endl;
			 

		choice = _getch();

		switch (choice)
		{
		case '1':
		{
			int lv;
			cout << "Wpisz jaki poziom ma mieæ postaæ" << endl;
			cin >> lv;
			p->LevelUp(lv);
			break;
		}
		case '2':
		{
			int hp;
			cout << "Wpisz jakie zdrowie ma mieæ postaæ" << endl;
			cin >> hp;
			p->hp = hp;
			break;
		}
		case '3':
		{
			int maxhp;
			cout << "Wpisz jakie maksymalne zdrowie ma mieæ postaæ" << endl;
			cin >> maxhp;
			p->maxhp;
			break;
		}
		case '4':
		{
			int def;
			cout << "Wpisz jak¹ obronê ma mieæ postaæ" << endl;
			cin >> def;
			p->defence = def;
			break;
		}
		case '5':
		{
			int mag;
			cout << "Wpisz jak¹ magiê ma mieæ postaæ" << endl;
			cin >> mag;
			p->magic = mag;
			break;
		}
		case '6':
		{
			int str;
			cout << "Wpisz jak¹ si³ê ma mieæ postaæ" << endl;
			cin >> str;
			p->strength = str;
			break;
		}
		case '7':
		{
			int eq;
			cout << "Wpisz jak¹ pojemnoœæ ekwipunku ma mieæ postaæ" << endl;
			cin >> eq;
			p->equipment = eq;
			break;
		}
		case '8':
		{
			int maxeq;
			cout << "Wpisz jak¹ si³ê ma mieæ postaæ" << endl;
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
