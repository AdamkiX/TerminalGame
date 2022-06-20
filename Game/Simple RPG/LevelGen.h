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
	vector<int> tilesX;				// Wektor wype³niany polami
	vector<int> tilesX0;			// Wektor wype³niony polami zerami

public:
	vector<vector<int>> tilesY;		// Wektor wype³niany wektorami pól
	friend class Rand;
	friend class Movement;
	friend class LoadGame;
	LevelGen();
	void DrawMap();						// Rysuje mapê
	void Generate();					// Generuje losowy poziom
	void Destroy();						// Niszczy poziom
	int GetZone();						// Przekazuje piêtro lochów
	vector<vector<int>> GetMap();		// Przekazuje ca³y poziom
};

#endif // !LEVELGEN_H