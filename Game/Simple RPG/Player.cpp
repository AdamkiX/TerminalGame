#include "Warior.h"
#include "Player.h"

#include <iostream>

void Player::Naming(int c)
{
	string n;
	cin >> n;
	this->name = n;

    switch (c)
    {
    case '1':
    {
        this->_class = "Wojownik";
        break;
    }
    case '2':
    {
        this->_class = "Mag";
        break;
    }
    case '3':
    {
        this->_class = "Z³odziej";
        break;
    }
    default:
    {
        break;
    }
    }
}

int Player::GetMoney()
{
    return gold;
}

void Player::ChangeMoney(int a)
{
    gold += a;
}

void Player::EquipmentUpdate(int i)
{
    equipment += i;
}
