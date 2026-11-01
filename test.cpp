#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/*struct Map
{
	short part;
	char symbol;
};

struct Unit
{
	short posX = 3, posY = 3, oldX, oldY;
};

int main()
{
	std::vector<Map> map; Unit unt;
	short i;
	bool run = 1;
	char temp;
	std::string line = "11 W 8 F 2 W 8 F 2 W 8 F 2 W 8 F 2 W 8 F 2 W 8 F 2 W 8 F 2 W 8 F 11 W";
	std::stringstream ss(line);

	while(ss >> i >> temp)
	{
		map.push_back({i, temp});
	};

	while(run)
	{
		unt.oldX = unt.posX; unt.oldY = unt.posY;

		for(short n = (unt.posY - 2); n >= (unt.posY - 2) && n <= (unt.posY + 2); n++)
		{
			if(n >= 0 && n < 10)
			{
				for(short j = (unt.posX - 2); j <= (unt.posX + 2); j++)
				{
					if(j < 0 || j >= 10)
					{
						cout << " ";
					}
					else
					{
						i = 0;
						for (short m = 0; m < map.size(); m++)
						{
						    if ((n * 10 + j) >= i && (n * 10 + j) < (i + map.at(m).part))
						    {
						        cout << map.at(m).symbol;
						        break;
						    }
						    i += map.at(m).part;
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

		cout << "\n\n" << unt.posX << " " << unt.posY << endl; cin >> temp;

		if(temp == 'W' || temp == 'w') unt.posY--; if(temp == 'S' || temp == 's') unt.posY++;
		if(temp == 'A' || temp == 'a') unt.posX--; if(temp == 'D' || temp == 'd') unt.posX++;
		if(temp == 'Q' || temp == 'q') run = 0;

		i = 0;
		for(short m = 0; m < map.size(); m++)
		{
			if(i <= (unt.posY * 10 + unt.posX) && (i + map.at(m).part) >= (unt.posY * 10 + unt.posX) && map.at(m).symbol == 'W')
			{
				unt.posX = unt.oldX; unt.posY = unt.oldY;
			}
			i += map.at(m).part;
		}

	};

	return 0;
}



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
				line.at(m) = line.at(n); line.at(n) = temp;
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
