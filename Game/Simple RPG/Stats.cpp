#include "Player.h"
#include "Enemy.h"

#include <iostream>
#include <string>

using namespace std;

void Player::Stats()
{
	string str1 = "", str2 = "";
	for (int i = 0; i < (46 - name.length())/2; i++)
	{
		cout << " ";
	}
	cout << name << endl
		<< "#############################################" << endl;
	cout << "#  Klasa  : " << _class; cout.width(33 - _class.length()); cout << right << "#" << endl;
	str1 = to_string(level);
	cout << "#  Poziom : " << level; cout.width(33 - str1.length()); cout << right << "#" << endl;
	str1 = to_string(exp);
	cout << "#  EXP    : " << exp << " / ";
	str2 = to_string(maxexp);
	cout << maxexp; cout.width(30 - (str1.length() + str2.length())); cout << right << "#" << endl;
	str1 = to_string(gold);
	cout << "#  Z³oto  : " << gold << "G"; cout.width(32 - str1.length()); cout << right << "#" << endl;
	str1 = to_string(hp);
	cout << "#  Zdrowie: " << hp << " / ";
	str2 = to_string(maxhp);
	cout << maxhp; cout.width(30 - (str1.length() + str2.length())); cout << right << "#" << endl;
	str1 = to_string(strength);
	cout << "#  Si³a   : " << strength; cout.width(33 - str1.length()); cout << right << "#" << endl;
	str1 = to_string(defence);
	cout << "#  Obrona : " << defence; cout.width(33 - str1.length()); cout << right << "#" << endl;
	str1 = to_string(magic);
	cout << "#  Magia  : " << magic; cout.width(33 - str1.length()); cout << right << "#" << endl;
	str1 = to_string(equipment);
	cout << "#  Plecak : " << equipment << " / ";
	str2 = to_string(maxequipment);
	cout << maxequipment; cout.width(30 - (str1.length() + str2.length())); cout << right << "#" << endl;
	str1 = to_string(actions);
	cout << "#  Akcje  : " << actions; cout.width(33 - str1.length()); cout << right << "#" << endl

		<< "#############################################" << endl << endl;

	system("pause");
	system("cls");

}


