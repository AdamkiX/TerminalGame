#include "Rand.h"

Rand::Rand()
{

}

void Rand::RandItem(int z, Inventory& inv, Player *p)
{
	Item* wsk = 0;
	int a = (z - 1) * 5 + 1;
	int b = z * 5 + 1;

	random_device r;
	mt19937 mt(r());
	uniform_int_distribution<int> uniform_dist(1, 3);
	int rand = uniform_dist(mt);

	switch (rand)
	{
	case 1:											// Wylosowano zbrojê
	{
		random_device r1;
		mt19937 mt1(r1());
		uniform_int_distribution<int> uniform_dist1a(1, 3);
		uniform_int_distribution<int> uniform_dist1b(a, b);
		int what = uniform_dist1a(mt1);
		int lv = uniform_dist1b(mt1);

		switch (what)
		{
		case 1:										// Wylosowano kolczugê
		{
			wsk = new Chainmail(lv, Item::id);
			break;
		}
		case 2:										// Wylosowano Szatê
		{
			wsk = new Robe(lv, Item::id);
			break;
		}
		case 3:										// Wylosowano p³aszcz
		{
			wsk = new Cloak(lv, Item::id);
			break;
		}
		}
		break;
	}
	case 2:											// Wylosowano broñ
	{
		random_device r2;
		mt19937 mt2(r2());
		uniform_int_distribution<int> uniform_dist2a(1, 3);
		uniform_int_distribution<int> uniform_dist2b(a, b);
		int lv = uniform_dist2b(mt2);
		int what = uniform_dist2a(mt2);
		switch (what)
		{
		case 1:
		{
			wsk = new Sword(lv, Item::id);
			break;
		}
		case 2:
		{
			wsk = new Dagger(lv, Item::id);
			break;
		}
		case 3:
		{
			wsk = new Staff(lv, Item::id);
			break;
		}
		}
		break;
	}
	case 3:
	{
		system("cls");
		random_device r3;
		mt19937 mt3(r3());
		uniform_int_distribution<int> uniform_dist3a(1, 3);
		uniform_int_distribution<int> uniform_dist3b(1, 2);
		uniform_int_distribution<int> uniform_dist3c(1, 5);
		int whata = uniform_dist3a(mt3);
		int whatb = uniform_dist3b(mt3);
		int count = uniform_dist3c(mt3);
		if (z <= 2)
		{
			inv.items[0]->count += (count);
			cout << "Podnosisz ma³e mikstury! Masz ich teraz: " << inv.items[0]->count << endl;

		}
		else if (z > 2 && z <= 4)
		{
			switch (whatb)
			{
			case 1:
			{
				inv.items[0]->count += (count);
				cout << "Podnosisz ma³e mikstury! Masz ich teraz: " << inv.items[0]->count << endl;
				break;
			}
			case 2:
			{
				inv.items[1]->count += (count);
				cout << "Podnosisz œrednie mikstury! Masz ich teraz: " << inv.items[1]->count << endl;
				break;
			}
			}
		}
		else
		{
			switch (whatb)
			{
			case 1:
			{
				inv.items[0]->count += (count);
				cout << "Podnosisz ma³e mikstury! Masz ich teraz: " << inv.items[0]->count << endl;
				break;
			}
			case 2:
			{
				inv.items[1]->count += (count);
				cout << "Podnosisz œrednie mikstury! Masz ich teraz: " << inv.items[1]->count << endl;
				break;
			}
			case 3:
			{
				inv.items[2]->count += (count);
				cout << "Podnosisz du¿e mikstury! Masz ich teraz: " << inv.items[2]->count << endl;
				break;
			}
			}
		}
		system("pause");
		break;
	}
	}

	if (wsk != 0)
	{
		system("cls");
		inv.AddItem(wsk,p);
		cout << "Znalaz³eœ przedmiot: " << endl;
		inv.ShowItemStats();
	}

}


Item* Rand::Create(Inventory& inv)
{
	int wybor = 0;
	Item *item = 0;
	cout << "Jaki przedmiot chcesz stworzyæ?" << endl;
	cout << "1. Zbrojê" << endl;
	cout << "2. Broñ" << endl;
	cout << "3 Miksturê zdorwia" << endl;

	wybor = _getch();

	switch (wybor)
	{
	case '1':
	{
		int classAr, lv;
		cout << "Dla jakiej klasy i na jaki poziom?" << endl;
		cout << "1. Wojownik" << endl;
		cout << "2. Mag" << endl;
		cout << "3. Z³odziej" << endl;

		cin >> classAr;
		cin >> lv;
		switch (classAr)
		{
		case 1:
		{
			item = new Chainmail(lv, Item::id);
			break;
		}
		case 2:
		{
			item = new Robe(lv, Item::id);
			break;
		}
		case 3:
		{
			item = new Cloak(lv, Item::id);
			break;
		}
		}
		break;
	}
	case '2':
	{
		int classAr, lv;
		cout << "Dla jakiej klasy i na jaki poziom?" << endl;
		cout << "1. Wojownik" << endl;
		cout << "2. Mag" << endl;
		cout << "3. Z³odziej" << endl;

		cin >> classAr;
		cin >> lv;
		switch (classAr)
		{
		case 1:
		{
			item = new Sword(lv,Item::id);
			break;
		}
		case 2:
		{
			item = new Staff(lv, Item::id);
			break;
		}
		case 3:
		{
			item = new Dagger(lv, Item::id);
			break;
		}
		}
		break;
	}
	case '3':
	{
		int choice = 0;
		int ammount = 0;

		cout << "Jakie mikstury zdrowia chcia³byœ sobie dodaæ?" << endl;
		cout << "1. Ma³e" << endl;
		cout << "2. Œrednie" << endl;
		cout << "3. Du¿e" << endl << endl;
		choice = _getch();

		cout << "Ile mikstur chcia³byœ dodaæ?" << endl;
		cin >> ammount;

		inv.items[choice - 49]->count += ammount;

		return 0;
	}
	}

	return item;
}

Rand::~Rand()
{

}