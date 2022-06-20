#include "Inventory.h"

Inventory::Inventory()
{
	posOfArmor = -1;
	posOfWeapon = -1;
	weaponEquiped = false;
	armorEquiped = false;
	item = 0;
}

void Inventory::AddPotHolder(Item* i)
{
	item = i;
	items.push_back(item);			
}

void Inventory::AddItem(Item* i)
{
	item = i;
	items.push_back(item);
}

void Inventory::AddItem(Item *i, Player *p)
{
	item = i;
	p->equipment++;
	items.push_back(item);
}

void Inventory::EquipWeapon(int i, Player *p)
{
	p->strength += items[i]->strength;
	p->magic += items[i]->magic;
	weaponEquiped = true;
	posOfWeapon = i;
	cout << "Ekwipowa³eœ broñ:	" << items[i]->name << " lv: " << items[i]->level << endl;
}

void Inventory::EquipArmor(int i, Player* p)
{
	p->defence += items[i]->defence;
	p->maxhp += items[i]->hp;
	p->strength += items[i]->strength;
	p->magic += items[i]->magic;
	armorEquiped = true;
	posOfArmor = i;
	cout << "Ekwipowa³eœ zbrojê:	" << items[i]->name << " lv: " << items[i]->level << endl;
}

void Inventory::EquipCheck(int i, Player *p)
{
	if (items[i]->class_ == p->_class)
	{
		if (items[i]->level <= p->level)
		{
			if (items[i]->weapon == true)
			{
				if (weaponEquiped == false)
				{
					EquipWeapon(i, p);
				}
				else
				{
					string choice;
					cout << "Masz ju¿ wyekwipowan¹ broñ. Czy chcesz j¹ zdj¹æ?" << endl;
					cout << "	Tak					Nie" << endl;
					cin >> choice;
					if (choice == "Tak" or "tak" or "t")
					{
						UnequipWeapon(p);
					}
				}
			}
			else if (items[i]->armor == true)
			{
				if (armorEquiped == false)
				{
					EquipArmor(i, p);
				}
				else
				{
					string choice;
					cout << "Masz ju¿ wyekwipowan¹ zbrojê. Czy chcesz j¹ zdj¹æ?" << endl;
					cin >> choice;
					if (choice == "Tak" or "tak" or "t")
					{
						UnequipArmor(p);
					}
				}
			}
		}
		else
			cout << "Masz za niski poziom by móc ekwipowaæ ten przedmiot!" << endl;
	}
	else
		cout << "Niestety, ale twoja postaæ nie umie pos³ugiwaæ siê tym przedmiotem" << endl;
}

void Inventory::Equip(Player* p)
{
	int i = 0;
	cout << "Jaki przedmiot chcesz ekwipowaæ?" << endl;
	i = InputCheck();
	i--;
	if (i < 3 or i >= items.size())
	{
		cout << "Nie mo¿na tego ekwipowaæ!" << endl;
	}
	else
	{
		EquipCheck(i,p);
	}

}

void Inventory::Unequip(Player* p)
{
	int choice = 0;
	cout << "Co zamierzasz zdj¹æ?" << endl
		<< "1. Zrojê" << endl << "2. Broñ" << endl;

	choice = _getch();

	switch (choice)
	{
	case '1':
	{
		if (armorEquiped == false)
		{
			cout << "Nie masz za³o¿onej zbroji!" << endl;
		}
		else
		{
			UnequipArmor(p);
			posOfArmor = 0;
		}
		break;
	}
	case '2':
	{
		if (weaponEquiped == false)
		{
			cout << "Nie masz wyekwipowanej broni!" << endl;
		}
		else
		{
			UnequipWeapon(p);
			posOfWeapon = 0;
		}
		break;
	}
	default:
	{
		cout << "Nie ma takiej opcji!" << endl;
	}
	}

}

void Inventory::UnequipWeapon(Player* p)
{
	p->defence -= items[posOfWeapon]->defence;
	p->hp -= items[posOfWeapon]->hp;
	p->strength -= items[posOfWeapon]->strength;
	p->magic -= items[posOfWeapon]->magic;
	weaponEquiped = false;
	cout << "Przestano u¿ywaæ: " << items[posOfWeapon]->name << " lv: " << items[posOfWeapon]->level << endl;
}

void Inventory::UnequipArmor(Player* p)
{
	p->defence -= items[posOfArmor]->defence;
	p->hp -= items[posOfArmor]->hp;
	p->strength -= items[posOfArmor]->strength;
	p->magic -= items[posOfArmor]->magic;
	armorEquiped = false;
	cout << "Zdjêto: " << items[posOfArmor]->name << "lv: " << items[posOfArmor]->level << endl;
}

void Inventory::ShowInvMenu(Player* p)
{

	bool exit = false;
	do
	{
		ShowInv();
		int choice = 0;
		cout << "Co chcesz zrobiæ? Wybierz odpowiadaj¹c¹ akcji liczbê:" << endl;
		cout << "	1. Zobaczyæ statystyki przedmiotu" << endl;
		cout << "	2. Ekwipowaæ przedmiot" << endl;
		cout << "	3. Zdj¹æ przedmiot" << endl;
		cout << "	4. Skonsumowaæ przedmiot" << endl;
		cout << "	5. Zniszczyæ przedmiot" << endl;
		cout << "	6. WyjdŸ z plecaka" << endl << endl;

		choice = _getch();

		switch (choice)
		{
		case '1':
		{
			CheckItem();
			break;
		}
		case '2':
		{
			Equip(p);
			system("pause");
			break;
		}
		case '3':
		{
			Unequip(p);
			system("pause");
			break;
		}
		case '4':
		{	
			UseHpPot(p);
			break;
		}
		case '5':
		{
			DestroyItem(p);
			system("pause");
			break;
		}
		case '6':
		{
			exit = true;
			break;
		}
		}
		system("cls");
		
	} while (exit == false);

}

void Inventory::ShowInv()
{
	string str = "";

	if (armorEquiped == true)
	{
		cout << "Wyekwipowana zbroja:	" << endl << "	" << items[posOfArmor]->name;
		cout.width(20 - items[posOfArmor]->name.length());
		cout << right << " lv: " << items[posOfArmor]->level << endl << endl;
	}
	if (weaponEquiped == true)
	{
		cout << "Wyekwipowana broñ:	" << endl << "	" << items[posOfWeapon]->name;
		cout.width(20 - items[posOfWeapon]->name.length());
		cout << right << " lv: " << items[posOfWeapon]->level << endl << endl;
	}


	cout << "Posiadasz nastêpuj¹ce mikstury: " << endl << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "	" << i + 1 << ". " << items[i]->name;
		cout.width(36 - items[i]->name.length());
		cout << right << " iloœæ: " << items[i]->count << endl << endl;
	}
	cout << "Posiadasz nastêpuj¹ce przedmioty: " << endl << endl;
	for (int i = 3; i < items.size(); i++)
	{
		cout << "	" << i + 1 << ". " << items[i]->name;
		str = to_string(i + 1);
		cout.width(22 - (items[i]->name.length()+str.length()));
		cout << right << " lv: " << items[i]->level << endl << endl;
	}
}

void Inventory::ShowItemStats()
{
	items[items.size()-1]->Stats();
}

void Inventory::CheckItem()
{
	int i = 0;
	do
	{	
		system("cls");
		ShowInv();
		cout << "Który przedmiot chcesz sprawdziæ? Wpisz odpowiadaj¹c¹ przedmiotowi liczbê" << endl;
		i = InputCheck();
		i--;
		system("cls");
	} while (i >= items.size());
	items[i]->Stats();
}



void Inventory::LoopAsk()
{
	string yn;
	bool choice = true;
	do
	{
		cout << "Czy chcesz podejrzeæ statystyki swoich przedmiotów?" << endl
			<< "	Tak						Nie" << endl;
		cin >> yn;
		if (yn == "tak" || yn == "Tak")
		{
			CheckItem();
		}
		else
			choice = false;
	} while (choice == true);
}

void Inventory::UseHpPot(Player *p)
{
	int choice = 0;
	cout << "Jak¹ miksturê zdrowia u¿yæ?" << endl
		<< "1. Ma³¹" << endl << "2. Œredni¹" << endl
		<< "3. Du¿¹" << endl << "4. Powrót" << endl;

	choice = _getch();
	
	switch (choice)
	{
	case '1':
	{
		CheckHpPots(choice, p);
		break;
	}
	case '2':
	{
		CheckHpPots(choice, p);
		break;
	}
	case '3':
	{
		CheckHpPots(choice, p);
		break;
	}
	default:
	{
		break;
	}
	}


}

void Inventory::CheckHpPots(int ch, Player* p)
{
	if (items[ch - 49]->count > 0)
	{
		p->hp += items[ch - 49]->hp;
		items[ch - 49]->count--;
		if (p->hp > p->maxhp)
		{
			p->hp = p->maxhp;
		}
	}
	else
		cout << "Nie masz mikstur!" << endl;
}

void Inventory::DestroyItem(Player *p)
{
	int i = 0;

	cout << "Który przedmiot chcesz zniszczyæ? Wpisz odpowiadaj¹c¹ przedmiotowi liczbê" << endl;
	cout << "jeœli nie chcesz niszczyæ przedmiotu wpisz 0" << endl;
	
	i = InputCheck();

	i--;
	system("cls");
	if (i == (-1))
	{
		cout << "Usuwanie przedmiotu zosta³o anulowane" << endl;
	}
	else if (i < 3 or i >= items.size())
	{
		cout << "Nie mo¿na tego zniszczyæ" << endl;
	}
	else
	{
		if (i == posOfArmor or i == posOfWeapon)
		{
			cout << "Musisz wpierw zdj¹æ ten przedmiot, by móc go zniszczyæ!" << endl;
		}
		else
		{
			items[i]->DestroyItem();
			it = items.begin() + i;
			items.erase(it);
			p->equipment--;

			if (i < posOfWeapon)
			{
				if (weaponEquiped == true)
				{
					posOfWeapon--;
				}
			}
			if (i < posOfArmor)
			{
				if (armorEquiped == true)
				{
					posOfArmor--;
				}
			}
			cout << "Przedmiot zosta³ zniszczony" << endl;
		}

	}


}

int Inventory::InputCheck()
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

void Inventory::EreaseItem(int what)
{
	it = items.begin() + what;
	items.erase(it);
	
	if (what < posOfWeapon)
	{
		if (weaponEquiped == true)
		{
			posOfWeapon--;
		}
	}
	if (what < posOfArmor)
	{
		if (armorEquiped == true)
		{
			posOfArmor--;
		}
	}

}

Inventory::~Inventory()
{
	for (int i = 0; i < items.size(); i++)
	{
		items[i]->DestroyItem();
		it = items.begin() + i;
		items.erase(it);
	}
	items.~vector();
}

void Inventory::AddStartPots()
{
	items[0]->count = 5;
}