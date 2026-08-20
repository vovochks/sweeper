#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main()
{
	system("clear");
	
	bool run = 1;
	short x, y;
	srand(time(NULL));
	std::string square[10] = {"XXXXXXXXXX",
				  "XXXXXXXXXX",
				  "XXXXXXXXXX",
				  "XXXXXXXXXX",
				  "XXXXXXXXXX",
				  "XXXXXXXXXX",
				  "XXXXXXXXXX",
				  "XXXXXXXXXX",
				  "XXXXXXXXXX",
				  "XXXXXXXXXX"};
	for(short n = 0; n < 10; ++n)
	{
		cout << square[n] << endl;
	}

	for(short i = 0; i < 10; ++i)
	{
		x = rand() % 10;
		y = rand() % 10;
		square[y][x] = '*';
	}
	
	while(run)
	{
		cout << "ENTER POS X, Y:";
		cin >> x >> y;

		if(square[y][x] == '*')
		{
			run = 0;
			
			cout << "\033[" << y + 1 << ";" << x + 1 << "H"; cout << square[y][x] << "\033[1;1H";

			system("clear");

			for(short m = 0; m < 10; ++m)
                        {
                                cout << square[m] << endl;
                        }

			cout << "\n\n ТЫ ПРОИГРАЛ..." << endl;

                        break;
		}
		else
		{
			short m = 0;
			
			if(x < 9 && square[y][x + 1] == '*') m++;
			if(x > 0 && square[y][x - 1] == '*') m++;
			if(y < 9 && square[y + 1][x] == '*') m++;
			if(y > 0 && square[y - 1][x] == '*') m++;
			if(x < 9 && y < 9 && square[y + 1][x + 1] == '*') m++;
			if(x > 0 && y < 9 && square[y + 1][x - 1] == '*') m++;
			if(x < 9 && y > 0 && square[y - 1][x + 1] == '*') m++;
			if(x > 0 && y > 0 && square[y - 1][x - 1] == '*') m++;

			square[y][x] = '0' + m;
			cout << "\033[" << y  + 1 << ";" << x + 1 << "H"; cout << m;

		}

		cout << "\033[11;1H";
	};

	return 0;
}
