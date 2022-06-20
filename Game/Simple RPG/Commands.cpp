#include "Commands.h"

Commands::Commands()
{
	devMode = false;
	password = "SwcNisw";
}

int Commands::DevMode()
{
	if (devMode == false)
	{
		string p;
		cin >> p;
		if (p == password)
		{
			devMode = true;
			return DevMenu();
		}
	}
	else
		DevMenu();
}

int Commands::DevMenu()
{
	int choice = 0;
	bool exit = false;
	do
	{


		cout << "Witamy w trybie deweloperskim. Proszê wybraæ jedn¹ z opcji:" << endl << endl;
		cout << "1. Dodaj przedmiot do ekwipunku" << endl;
		cout << "2. Rozpocznij walkê" << endl;
		cout << "3. PrzejdŸ na ni¿sze piêtro" << endl;
		cout << "4. Edytuj atrubuty gracza" << endl;
		cout << "5. Wyjœcie" << endl << endl;

		cin >> choice;

		if (choice >= 1 && choice <= 5)
		{
			exit = true;
		}

		system("cls");
	} while (exit == false);

	return choice;
}

Commands::~Commands()
{

}
