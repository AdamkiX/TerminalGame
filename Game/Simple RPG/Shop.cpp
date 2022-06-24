#include "Shop.h"

Shop::Shop()
{
	ammOfGen = 0;
}

Shop::Shop(int z)
{
	it = store.begin();
	ammOfGen = 0;
	Item* wsk = 0;
	wsk = new SmallHpPotion;
	store.push_back(wsk);
	wsk = new MedHpPotion;
	store.push_back(wsk);
	wsk = new LargeHpPotion;
	store.push_back(wsk);

	store[0]->count = 0;
	store[1]->count = 0;
	store[2]->count = 0;

	do
	{
		GenerateShop(z);
		ammOfGen++;
	} while (ammOfGen < 8);

}

void Shop::AddItem(Item *i)
{
	store.push_back(i);
}

void Shop::GenerateShop(int z)
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
			store[0]->count += (count);
			wsk = 0;

		}
		else if (z > 2 && z <= 4)
		{
			switch (whatb)
			{
			case 1:
			{
				store[0]->count += (count);
				wsk = 0;
				break;
			}
			case 2:
			{
				store[1]->count += (count);
				wsk = 0;
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
				store[0]->count += (count);
				wsk = 0;
				break;
			}
			case 2:
			{
				store[1]->count += (count);
				wsk = 0;
				break;
				}
			case 3:
			{
				store[2]->count += (count);
				wsk = 0;
				break;
			}
			}
		}
		break;
	}
	}

	if (wsk != 0)
	{
		store.push_back(wsk);
	}
}

void Shop::ShopMenu(Player *p, Inventory& inv)
{
	int choice = 0;;
	int exit = false;

	cout << "Witaj wêdrowcze w moim sklepie..." << endl;
	cout << "Nie masz nic przeciwko, aby pohandlowaæ?" << endl << endl;
	do
	{
		cout << "#########################" << endl;
		cout << "1. Kup przedmiot" << endl << "2. Sprzedaj przedmiot" << endl
			<< "3. WyjdŸ ze sklepu" << endl << endl;

		cout << "Posiadasz: " << p->GetMoney() << "G" << endl;

		choice = _getch();

		switch (choice)
		{
		case '1':
		{
			ShopStorage(p,inv);
			break;
		}
		case '2':
		{
			PlayerStorage(p,inv);
			break;
		}
		case '3':
		{
			cout << "Wychodzisz? W takim razie ¿yczê Ci powodzenia w lochcach" << endl;
			system("pause");
			exit = true;
			break;
		}
		default:
		{
			cout << "Niewiem co to mia³o znaczyæ? Zdecyduj siê na coœ" << endl;
			system("pause");
			break;
		}
		}


		system("cls");
	} while (exit == false);
}

void Shop::ShopStorage(Player *p,Inventory& inv)
{
	system("cls");

	string str;
	int choice;
	cout << endl;
	cout << "Masz tu listê rzeczy, przyjrzyj siê jej... Mo¿e przypadnie Ci coœ do gustu?" << endl << endl;
	cout << "		LISTA PRZEDMIOTÓW		" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << ". " << store[i]->name;
		cout.width(36 - store[i]->name.length());
		cout << right << " iloœæ: " << store[i]->count << endl;
		cout << "	Koszt za sztukê: "; 
		cout.width(5); 
		cout << store[i]->goldValue << "G" << endl << endl;
	}
	cout << endl;
	for (int i = 3; i < store.size(); i++)
	{
		cout << "	" << i + 1 << ". " << store[i]->name;
		str = to_string(i + 1);
		cout.width(22 - (store[i]->name.length() + str.length()));
		cout << right << " lv: " << store[i]->level << endl;
		cout << "	Koszt: ";
		cout.width(5);
		cout << store[i]->goldValue << "G" << endl << endl;
	}
	cout << store.size() + 1 <<" Powrót" << endl << endl << endl;

	cout << "Posiadasz: " << p->GetMoney() << "G" << endl;

	choice = InputCheck();
	choice--;
	if (choice < store.size() && choice >=0)
	{
		BuyItem(p, inv, choice);
	}
	else if (choice == store.size() + 1)
	{

	}
	else if (choice > store.size()+1)
	{
		cout << "Hmmm... Nie mam tego przedmiotu na liœcie" << endl;
		system("pause");
	}
}

void Shop::BuyItem(Player *p,Inventory& inv, int choice)
{
	system("cls");

	string choice2;
	bool buy = false;
	int ammount = 0, cost = 0;

		cout << "Chcesz kupiæ: " << store[choice]->name << " za: " << store[choice]->goldValue << "G?" << endl;
		cout << "	Tak		Nie" << endl << endl;
		cin >> choice2;

		cout << "Posiadasz: " << p->GetMoney() << "G" << endl;

	if (choice2 == "Tak" or choice2 == "tak" or choice2 == "t")
	{
		if (choice < 3)
		{
			cout << "Super! Ile chcia³byœ kupiæ?" << endl;
			ammount = InputCheck();
			if (ammount > store[choice]->count)
			{
				cout << "Ups... Nie posiadam tyle mikstur..." << endl;
				system("pause");
			}
			else
			{
				cost = ammount * store[choice]->goldValue;
				buy = CanAfford(p, cost);
				if (buy == true)
				{
					p->ChangeMoney((-cost));
					inv.items[choice]->count += ammount;
					store[choice]->count -= ammount;
					cout << endl << "Posiadasz: " << p->GetMoney() << "G" << endl;
					system("pause");
				}
				else
				{
					cout << "Przykro mi, ale nie staæ Ciê na to" << endl;
					system("pause");
				}
			}
				
		}
		else
		{
			ammount = 1;
			cost = ammount * store[choice]->goldValue;
			buy = CanAfford(p, cost);
			if (buy == true)
			{
				p->ChangeMoney((-cost));
				inv.items.push_back(store[choice]);
				it = store.begin() + choice;
				store.erase(it);
				p->EquipmentUpdate(1);
				cout << endl << "Posiadasz: " << p->GetMoney() << "G" << endl;
			}
			else
			{
				cout << "Przykro mi, ale nie staæ Ciê na to" << endl;
				system("pause");
			}
		}
	}
	else if (choice2 == "Nie" or choice2 == "nie" or choice2 == "n")
	{

	}

}

bool Shop::CanAfford(Player *p, int c)
{
	int pGold;
	pGold = p->GetMoney();
	if (pGold >= c)
	{
		return true;
	}
	else
		return false;
}

int Shop::InputCheck()
{
	int i;

	cin >> i;

	while (!cin.good())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		cin >> i;
	}
	return i;
}

void Shop::PlayerStorage(Player *p, Inventory& inv)
{
	system("cls");

	string str;
	int choice = 0;
	cout << endl;
	cout << "Dobra! Poka¿ mi konkretny przedmiot: " << endl << endl;
	inv.ShowInv();
	cout << inv.items.size() + 1 << " Powrót" << endl << endl << endl;

	choice = InputCheck();
	choice--;
	if (choice < inv.items.size() && choice >= 0)
	{
		if (choice == inv.posOfArmor or choice == inv.posOfWeapon)
		{
			cout << "Nie korzystasz przypadkiem teraz z tego przedmiotu?" << endl;
			cout << "WyjdŸ ze sklepu i zastanów siê czy na pewno chcesz mi to sprzedaæ..." << endl;
			system("pause");
		}
		else
			SellItem(p, inv, choice);
	}
	else if (choice == inv.items.size())
	{

	}
	else
	{
		cout << "Hmmm... Ale tu nic nie ma" << endl;
		system("pause");
	}

}

void Shop::SellItem(Player* p, Inventory& inv, int choice)
{
	system("cls");

	string choice2;
	bool buy = false;
	int ammount = 0, cost = 0, pGold = 0;

		cout << "Chcesz sprzedaæ: " << inv.items[choice]->name << "?" << endl;
		cout << "Dam Ci za ka¿d¹ sztukê: " << (inv.items[choice]->goldValue) / 2 << "G" << endl;
		cout << "	Tak		Nie" << endl << endl;
		cin >> choice2;

	if (choice2 == "Tak" or choice2 == "tak" or choice2 == "t")
	{
		if (choice < 3)
		{
			cout << "Super! Ile chcia³byœ sprzedaæ?" << endl;
			ammount = InputCheck();
			if (ammount > inv.items[choice]->count)
			{
				cout << "Ups... Nie posiadasz tyle mikstur..." << endl;
				system("pause");
			}
			else
			{
				cost = (ammount * inv.items[choice]->goldValue) / 2;
				p->ChangeMoney(cost);
				inv.items[choice]->count -= ammount;
				store[choice]->count += ammount;
				cout << endl << "Posiadasz: " << p->GetMoney() << "G" << endl;
			}

		}
		else
		{
			ammount = 1;
			cost = (ammount * inv.items[choice]->goldValue) / 2;
			p->ChangeMoney(cost);
			store.push_back(inv.items[choice]);
			inv.EreaseItem(choice);
			p->EquipmentUpdate(-1);
			cout << endl << "Posiadasz: " << p->GetMoney() << "G" << endl;
		}		
	}
	else if (choice2 == "Nie" or choice2 == "nie" or choice2 == "n")
	{

	}

}

Shop::~Shop()
{
	for (int i = 0; i < store.size(); i++)
	{
		store[i]->DestroyItem();
	}
	store.clear(); store.shrink_to_fit();
}

void Shop::ShowShop()
{
	string str = "";
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << ". " << store[i]->name;
		cout.width(36 - store[i]->name.length());
		cout << right << " iloœæ: " << store[i]->count << endl;
		cout << "	Koszt za sztukê: ";
		cout.width(5);
		cout << store[i]->goldValue << "G" << endl << endl;
	}
	cout << endl;
	for (int i = 3; i < store.size(); i++)
	{
		cout << "	" << i + 1 << ". " << store[i]->name;
		str = to_string(i + 1);
		cout.width(22 - (store[i]->name.length() + str.length()));
		cout << right << " lv: " << store[i]->level << endl;
		cout << "	Koszt: ";
		cout.width(5);
		cout << store[i]->goldValue << "G" << endl << endl;
	}
}