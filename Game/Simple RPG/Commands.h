#pragma once

#include <conio.h>
#include <iostream>

using namespace std;

class Commands
{
private:
	string password;
	int DevMenu();		// Menu trybu deweloperskiego

public:
	static bool devMode;
	Commands();			// Konstruktor
	int DevMode();		// Wywo³anie trybu deweloperskiego
	~Commands();		// Destruktor
};

