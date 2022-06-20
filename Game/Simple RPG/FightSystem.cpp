#include "FightSystem.h"

FightSystem::FightSystem()
{
	won = false;
	end = false;
	Pturns = 0;
	turn = 1;
	zone = 0;
	fighting = false;
}

bool FightSystem::FightCheck(Player *p, Inventory& inv, int i)
{
	zone = i;
	if (fighting == true)
	{
		Pturns = p->actions;
		bool alive;
		alive = Fight(p, inv);
		return alive;
	}
	else
		return 1;
}

int FightSystem::RandEnemyNum()
{
	random_device r;
	mt19937 mt(r());
	uniform_int_distribution<int> uniform_dista(1, 2);
	uniform_int_distribution<int> uniform_distb(1, 3);
	bool check;
	if (zone == 1 or (zone % 6 == 0 and Movement::bossRoom == 6))
	{
		return 1;
	}
	else if (zone == 2)
	{
		return uniform_dista(mt);
	}
	else
		return uniform_distb(mt);

}

void FightSystem::GenerateEnemy()
{
	Enemy* e;
	int a = (zone - 1) * 4 + 1;
	int b = zone * 4 + 1;
	random_device r;
	mt19937 mt(r());
	uniform_int_distribution<int> uniform_dista(1, 2);
	uniform_int_distribution<int> uniform_distb(a, b);
	uniform_int_distribution<int> uniform_distc(1, 3);
	int kind = uniform_dista(mt);
	int level = uniform_distb(mt);
	int class_ = uniform_distc(mt);

	if (zone < 3)
	{
		if (kind == 1)
		{
			e = new Goblin(level);
		}
		else
		{
			e = new Orc(level);
		}
	}
	else if (zone >= 3 && zone < 5)
	{
		if (kind == 1)
		{
			if (level < 3 + 5*zone)
			{
				e = new GoblinMage(level);
			}
			else
				e = new Goblin(level);
		}
		else
		{
			if (level < 3 + 5 * zone)
			{
				e = new OrcMage(level);
			}
			else
				e = new Orc(level);
		}
	}
	else if (zone % 6 == 0 and Movement::bossRoom == 6)
	{
		e = new Boss(zone * 5);
	}
	else
	{
		if (kind == 1)
		{
			switch (class_)
			{
			case 1:
			{
				e = new Goblin(level);
			}
			case 2:
			{
				e = new GoblinMage(level);
			}
			case 3:
			{
				e = new GoblinRogue(level);
			}
			}
		}
		else
		{
			switch (class_)
			{
			case 1:
			{
				e = new Orc(level);
			}
			case 2:
			{
				e = new OrcMage(level);
			}
			case 3:
			{
				e = new OrcWarior(level);
			}
			}
		}
	}

	enemys.push_back(e);
}

bool FightSystem::Fight(Player* p, Inventory& inv)
{

	won = false;
	end = false;
	int enemyNum = 0;
	enemyNum = RandEnemyNum();
	for (int i = 0; i < enemyNum; i++)
	{
		GenerateEnemy();
	}

	system("cls");
	cout << "Z³o stoi na twojej drodze!" << endl;

	for (int i = 0; i < enemys.size(); i++)
	{
		enemys[i]->Stats();
	}
	system("pause");

	do
	{
		p->Ability(turn);
		for (int i = 0; i < p->actions; i++)
		{
			PlayerTurn(p,inv);
		}
		for (int i = 0; i < enemys.size(); i++)
		{
			EnemyDeathCheck(i, p);
		}
		for (int i = 0; i < enemys.size(); i++)
		{
			EnemyTurn(i, p);
		}
		if (p->hp <= 0)
		{
			system("cls");
			won = false;
			end = true;
			cout << "Nie jesteœ wstanie ustaæ od otrzymanych obra¿eñ. Twoja przygoda koñczy siê tutaj" << endl;
		}			
	p->actions = Pturns;

	if (end == false)
	{
		turn++;
	}
	} while (end == false);

	turn = 0;
	p->Ability(turn);
	turn = 1;

	fighting = false;
	return won;
}

void FightSystem::PlayerTurn(Player *p, Inventory &inv)
{
	int  option = 0;
	int actions = p->actions;

	system("cls");
	cout << endl << "Tura : " << turn << endl << endl;
	for (int i = 0; i < enemys.size(); i++)
	{
		cout << i+1 << ". " << enemys[i]->name;
		cout.width(16 - enemys[i]->name.size());
		cout << " Lv : " << enemys[i]->level << endl <<" Zdrowie: " << enemys[i]->hp << " / " << enemys[i]->maxhp << endl << endl;
	}

	cout << "Twoje zdrowie wynosi:	" << p->hp << " / " << p->maxhp << endl << endl;
	cout << "Masz nastepujace opcje:" << endl << "1. Atak" << endl << "2. Ulecz siê" << endl
		<< "3. Statystyki" << endl << "4. Wyœwietl ekwipunek" << endl << endl;
	cout << "Pozosta³e akcje: " << actions << endl;

	option = _getch();

	switch (option)
	{
	case '1':
	{
		PlayerAttack(p);
		actions--;
		break;
	}
	case '2':
	{
		inv.UseHpPot(p);
		actions--;
		break;
	}
	case '3':
	{
		EveryoneStats(p);
		actions--;
		system("pause");
		break;
	}
	case '4':
	{
		inv.ShowInv();
		actions--;
		system("pause");
		break;
	}
	default :
	{
		cout << "Nie ma takiej opcji!" << endl;
		actions--;
		system("pause");
	}
	}


}

void FightSystem::PlayerAttack(Player* p)
{
	int dmg = 0, who = 0;

	if (enemys.size() > 1)
	{
		cout << "Którego przeciwnika chcesz zaatakowaæ?" << endl;
		who = _getch();
	}
	else
		who = 0;
	if (who > enemys.size())
	{
		who -= 49;
	}
	else if (who < 0)
	{
		who = 0;
	}
	if (p->magic > p->strength)
	{
		dmg = (p->magic - enemys[who]->defence);
		enemys[who]->hp -= dmg;
	}
	else
	{
		dmg = (p->strength - enemys[who]->defence);
		enemys[who]->hp -= dmg;
	}

}

void FightSystem::EveryoneStats(Player *p)
{
	cout << "Twoje statystyki: " << endl;
	p->Stats();
	for (int i = 0; i < enemys.size(); i++)
	{
		cout << endl;
		enemys[i]->Stats();
	}
}

void FightSystem::EnemyTurn(int i, Player* p)
{
	int dmg = 0;
	cout << enemys[i]->name << " atakuje!" << endl;
	dmg = (enemys[i]->damage - p->defence);
	if (dmg <= 0)
	{
		dmg = 1;
	}
	p->hp -= dmg;

}

void FightSystem::EnemyDeathCheck(int i,Player* p)
{
	if (enemys[i]->hp <= 0)
	{
		system("cls");
		cout << "Gratulacjê! Przeciwnik zosta³ pokonany!" << endl
			<< "Zdobyte doœwiadczenie: " << enemys[i]->exp << endl;
		Sleep(2000);
		p->exp += enemys[i]->exp;
		if (p->exp >= p->maxexp)
		{
			p->Ability(0);
			p->LevelUp(p->level + 1);
		}
		enemys[i]->DestroyEnemy();
		it = enemys.begin() + i;
		enemys.erase(it);
	}
	if (enemys.size() == 0)
	{
		won = true;
		end = true;
	}
}

FightSystem::~FightSystem()
{

}