#ifndef LEVELGEN_H
#define LEVELGEN_H

#include "Rand.h"

#include <iostream>
#include <vector>
#include <random>

using namespace std;

class LevelGen
{
private:
	int zone;
	vector<int> tilesX;				// Wektor wype�niany polami
	vector<int> tilesX0;			// Wektor wype�niony polami zerami

public:
	vector<vector<int>> tilesY;		// Wektor wype�niany wektorami p�l
	friend class Rand;
	friend class Movement;
	friend class LoadGame;
	LevelGen();
	void DrawMap();						// Rysuje map�
	void Generate();					// Generuje losowy poziom
	void Destroy();						// Niszczy poziom
	int GetZone();						// Przekazuje pi�tro loch�w
	vector<vector<int>> GetMap();		// Przekazuje ca�y poziom
};

#endif // !LEVELGEN_H