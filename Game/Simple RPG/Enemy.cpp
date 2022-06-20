#include "Enemy.h"

void Enemy::Stats()
{
	string str1 = "", str2 = "";
	for (int i = 0; i < 23 - name.length(); i++)
	{
		cout << " ";
	}
	cout << name << endl
		<< "#############################################" << endl;
	str1 = to_string(level);
	cout << "#  Poziom : " << level; cout.width(33 - str1.length()); cout << right << "#" << endl;
	str1 = to_string(hp);
	cout << "#  Zdrowie: " << hp << " / ";
	str2 = to_string(maxhp);
	cout << maxhp; cout.width(30 - (str1.length() + str2.length())); cout << right << "#" << endl;
	str1 = to_string(strength);
	cout << "#  Sila   : " << strength; cout.width(33 - str1.length()); cout << right << "#" << endl;
	str1 = to_string(defence);
	cout << "#  Obrona : " << defence; cout.width(33 - str1.length()); cout << right << "#" << endl;
	str1 = to_string(magic);
	cout << "#  Magia  : " << magic; cout.width(33 - str1.length()); cout << right << "#" << endl;
	cout << "#############################################" << endl << endl;

}
