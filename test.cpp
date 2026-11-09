#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

const short view = 15;

struct Matrix
{
	short part;
	char symbol;
};


struct Unit
{
	bool player;
	short posX = 0, posY = 0, posZ = 0, oldX, oldY, oldZ;
};

struct Map
{
	std::string address, name;
	short size = 256, vecZ = 3;
	bool check;
	std::vector<Matrix> mtrx;

	void Read();
};

void layout(char task)
{
	switch(task)
	{
		case 'm':
		{
			cout << "\033[2;2H";
			break;
		}
		case 'l':
		{
			for(short i = 1; i <= 24; i++)
			{
				if(i == 1 || i == 24 || i == 17)
				{
					for(short j = 1; j <= 80; j++)
					{
						cout << "\033[" << i << ";" << j << "H" << "=";
					}
				}
				else
				{
					if(i < 18 || i > 23) cout << "\033[" << i << ";1H" << "|" << "\033[" << i << ";47H" << "|" << "\033[" << i << ";80H" << "|";
					else cout << "\033[" << i << ";1H" << "|" << "\033[" << i << ";80H" << "|";
				}
			}
			break;
		}
		default:
		{
		}
	}
}

void Map::Read()
{
	ifstream mapFile("test.txt");

	int i;
	std::string line;
	char temp;

	if(!mapFile.is_open())
	{
	}
	else
	{
		getline(mapFile, line);
	}

	std::stringstream ss(line);

	while(ss >> i >> temp)
	{
		mtrx.push_back({i, temp});
	};

	i = 0;

	for(short n = 0; n < mtrx.size(); n++)
	{
		i += mtrx.at(n).part;
	}

	if(i != (size * size * vecZ)) check = 0; else check = 1;
}

int main()
{
	system("clear");

	Map map; Unit unt;
	int i;
	bool run = 1;
	char temp;

	map.Read();

	while(run)
	{
		unt.oldX = unt.posX; unt.oldY = unt.posY; unt.oldZ = unt.posZ;

		layout('l');
		layout('m');

/*		for(short n = (unt.posY - (view / 2)); n >= (unt.posY - (view / 2)) && n <= (unt.posY + (view / 2)); n++)
		{
			if(n >= 0 && n < map.size)
			{
				for(short j = (unt.posX - (view * 3 / 2)); j <= (unt.posX + (view * 3 / 2)); j++)
				{
					if(j < 0 || j >= map.size)
					{
						cout << " ";
					}
					else
					{
						i = 0;

						for(short m = 0; m < map.mtrx.size(); m++)
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
				for(short m = 1; m <= (view * 3); m++) cout << " ";
			}

			cout << "\n" << "\033[2G";
*/		}

		cout << "\033[16;48H>"; cin >> temp; cout << "\033[A";

		if(temp == 'W' || temp == 'w') unt.posY--; if(temp == 'S' || temp == 's') unt.posY++;
		if(temp == 'A' || temp == 'a') unt.posX--; if(temp == 'D' || temp == 'd') unt.posX++;
		if(temp == 'F' || temp == 'f') unt.posZ++; if(temp == 'G' || temp == 'g') unt.posZ--;
		if(temp == 'Q' || temp == 'q') run = 0;

		i = 0;
/*		for(short m = 0; m < map.mtrx.size(); m++)
		{

			if(i <= ((unt.posY * map.size + unt.posX) + (map.size * map.size * unt.posZ)) &&
			  (i + map.mtrx.at(m).part) > ((unt.posY * map.size + unt.posX) + (map.size * map.size * unt.posZ)) &&
			  map.mtrx.at(m).symbol == 'W')
			{
				unt.posX = unt.oldX; unt.posY = unt.oldY; unt.posZ = unt.oldZ; break;
			}

			if(unt.posX < 0 || unt.posX >= map.size || unt.posY < 0 || unt.posY >= map.size || unt.posZ < 0 || unt.posZ >= map.vecZ)
			{
				unt.posX = unt.oldX; unt.posY = unt.oldY; unt.posZ = unt.oldZ; break;
			}
			i += map.mtrx.at(m).part;
		}
*/
	};

	return 0;
}
