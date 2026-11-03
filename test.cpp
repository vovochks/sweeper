#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Pointer
{
	std::vector<short> ptrL;
	std::vector<short> ptrP;
};

struct Matrix
{
	short part;
	char symbol;
};

struct Map
{
	std::string address, name;
	short size = 10, vecZ = 2;
	std::vector<Matrix> mtrx;
};

struct Unit
{
	bool player;
	short posX = 3, posY = 3, posZ = 0, oldX, oldY, oldZ;
};

int main()
{
	Map map; Unit unt;
	short i;
	bool run = 1;
	char temp;
	std::string line = "10 F 1 W 8 F 2 W 8 F 2 W 8 F 2 W 8 F 2 W 8 F 2 W 8 F 2 W 8 F 2 W 8 F 1 W 10 F ";

	for(short k = 0; k < 2; k++) line = line + "11 W 8 F 2 W 8 F 4 W 4 F 4 W 8 F 4 W 4 F 4 W 8 F 2 W 8 F 2 W 8 F 11 W ";

	std::stringstream ss(line);

	while(ss >> i >> temp)
	{
		map.mtrx.push_back({i, temp});
	};

	while(run)
	{
		unt.oldX = unt.posX; unt.oldY = unt.posY; unt.oldZ = unt.posZ;

		for(short n = (unt.posY - 2); n >= (unt.posY - 2) && n <= (unt.posY + 2); n++)
		{
			if(n >= 0 && n < map.size)
			{
				for(short j = (unt.posX - 2); j <= (unt.posX + 2); j++)
				{
					if(j < 0 || j >= map.size)
					{
						cout << " ";
					}
					else
					{
						i = 0;
						for (short m = 0; m < map.mtrx.size(); m++)
						{
						    if(((n * map.size + j) + (map.size * map.size * unt.posZ)) >= i &&
							((n * map.size + j) + (map.size * map.size * unt.posZ)) < (i + map.mtrx.at(m).part))
						    {
						        cout << map.mtrx.at(m).symbol;
						        break;
						    }
						    i += map.mtrx.at(m).part;
						}
					}
				}

			}
			else
			{
				for(short m = (unt.posX - 2); m >= (unt.posX - 2) && m <= (unt.posX + 2); m++) cout << " ";
			}

			cout << "\n";
		}

		cout << "\n\n" << unt.posX << " " << unt.posY << " " << unt.posZ << " " << map.vecZ << endl; cin >> temp;

		if(temp == 'W' || temp == 'w') unt.posY--; if(temp == 'S' || temp == 's') unt.posY++;
		if(temp == 'A' || temp == 'a') unt.posX--; if(temp == 'D' || temp == 'd') unt.posX++;
		if(temp == 'F' || temp == 'f') unt.posZ++; if(temp == 'G' || temp == 'g') unt.posZ--;
		if(temp == 'Q' || temp == 'q') run = 0;

		i = 0;
		for(short m = 0; m < map.mtrx.size(); m++)
		{
			if(i <= ((unt.posY * map.size + unt.posX) + (map.size * map.size * unt.posZ)) &&
			  (i + map.mtrx.at(m).part) > ((unt.posY * map.size + unt.posX) + (map.size * map.size * unt.posZ)) &&
			  map.mtrx.at(m).symbol == 'W')
			{
				unt.posX = unt.oldX; unt.posY = unt.oldY; unt.posZ = unt.oldZ;
			}
			if(unt.posX < 0 || unt.posX >= map.size || unt.posY < 0 || unt.posY >= map.size || unt.posZ < 0 || unt.posZ >= map.vecZ)
			{
				unt.posX = unt.oldX; unt.posY = unt.oldY; unt.posZ = unt.oldZ;
			}
			i += map.mtrx.at(m).part;
		}

	};

	return 0;
}

/*
int main()
{
	std::vector<int> line;

	int temp;

	for(int i = 0; i < 8; i++)
	{
		cin >> temp;

		line.push_back(temp);
	}

	cout << "\n\n";

	for(int i = 0; i < 8; i++)
	{
		cout << line.at(i) << " ";
	}


	cout << "\n\n";

	for(int n = 0; n < line.size(); n++)
	{
		for(int m = line.size() - 1; m >= n; m--)
		{

			temp = line.at(m);

			if(temp > line.at(n))
			{
				line.at(m) = line.at(n);line.at(n) = temp;
			}
		}
	}

	for(int i = 0; i < 8; i++)
	{
		cout << line.at(i) << " ";
	}

	return 0;
}

*/
