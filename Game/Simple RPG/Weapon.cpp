#include "Weapon.h"

void Weapon::Stats()
{
	string str1 = "", str2 = "";
	for (int i = 0; i < (46 - name.length()) / 2; i++)
	{
		cout << " ";
	}
	cout << name << endl
		<< "#############################################" << endl;
	cout << "#  Klasa   : " << class_; cout.width(32 - class_.length()); cout << right << "#" << endl;
	str1 = to_string(level);
	cout << "#  Poziom  : " << level; cout.width(32 - str1.length()); cout << right << "#" << endl;
	str1 = to_string(goldValue);
	cout << "#  Wartoœæ : " << goldValue; cout.width(32 - str1.length()); cout << right << "#" << endl;
	str1 = to_string(strength);
	cout << "#  Sila    : " << strength; cout.width(32 - str1.length()); cout << right << "#" << endl;
	str1 = to_string(magic);
	cout << "#  Magia   : " << magic; cout.width(32 - str1.length()); cout << right << "#" << endl
		<< "#############################################" << endl << endl;

	system("pause");
}
