#include "LevelGen.h"

LevelGen::LevelGen()
{
	zone = 0;
}

void LevelGen::Generate()
{
	zone++;
	int n = 6;
	int total_tiles = 5 * n + 5 * zone;
	int sizeX = n + zone;
	int maxRand = 95;
	bool shop = false;

	if (68 + zone <= 95)
	{
		maxRand = 68 + zone;
	}

	for (int j = 0; j < sizeX; j++)
	{
		tilesX0.push_back(0);
	}
	tilesY.push_back(tilesX0);
	tilesX0.clear();	tilesX0.shrink_to_fit();


	for (int i = 0; i < (total_tiles); i++)
	{
		random_device r1;
		random_device r2;
		default_random_engine e1(r1());
		default_random_engine e2(r2());
		uniform_int_distribution<int> uniform_dist1(1, 4);
		uniform_int_distribution<int> uniform_dist2(1, 100);
		int direction = uniform_dist2(e2);
		int room = uniform_dist1(e1);

		if (tilesX.size() <= 1 or (direction < maxRand && tilesX.size() < sizeX-1))
		{
			if (tilesX.size() == 0)
			{
				tilesX.push_back(0);
			}
			if (shop == true && room == 4)
			{
				if (direction > maxRand/2)
					tilesX.push_back(1);
				else
					tilesX.push_back(2);
			}
			else
				tilesX.push_back(room);
			if (room == 4)
			{
				shop = true;
			}
		}
		else
		{
			do
			{
				tilesX.push_back(0);
			} while (tilesX.size() < sizeX);
			tilesY.push_back(tilesX);
			tilesX.clear();		tilesX.shrink_to_fit();
		}

	}

	for (int j = 0; j < sizeX; j++)
	{
		tilesX0.push_back(0);
	}
	tilesY.push_back(tilesX0);
	tilesX0.clear();	tilesX0.shrink_to_fit();
	for (int i = 1; i < sizeX; i++)
	{
		if (tilesY[1][i + 1] == 0)
		{
			tilesY[1][i] = 7;
			break;
		}
	}
	tilesY[tilesY.size()-2][1] = 5;


	if (zone == 6)
	{
		tilesY[tilesY.size() - 3][1] = 6;
	}

}

void LevelGen::DrawMap()
{
	cout << "POZIOM: " << zone << endl << endl;

	for (int i = 0; i < tilesY.size(); i++)
	{
		for (int j = 0; j < tilesY[i].size(); j++)
		{
			if (tilesY[i][j] == 0)
				cout << "[]";
			else if (tilesY[i][j] == 7)
				cout << "^^";
			else
				cout << "  ";
		}
		cout << endl;
	}
}

vector<vector<int>> LevelGen::GetMap()
{
	return tilesY;
}

void LevelGen::Destroy()
{
	tilesY.clear();		tilesY.shrink_to_fit();
}

int LevelGen::GetZone()
{
	return zone;
}