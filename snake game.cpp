#include<iostream>
#include<string>
#include<conio.h>
#include<vector>
#include<Windows.h>
#include<stdio.h>
#include<time.h>
using namespace std;
const int width = 30;
const int height = 20;
bool gameover = 0, inrange = 0;
int x = 15, y = 10, foodx = rand() % height, foody = rand() % width, score = 0, bigfood = 0;
int tail_length = 0;
int tailx[50], taily[50], lastx, lasty, tempx, tempy;
bool space;
int choice_level;


string player_name;


void input()
{
	if (_kbhit)
	{
		switch (_getch())
		{
		case'a':
			x--;
			
			if (x == 0 || x == 30)
			{
				if (x == 0)x = 29;
				else x = 1;
			}
			for (int i = 0; i < tail_length; i++)
			{
				if (x == tailx[i] && y == taily[i])
				{
					gameover = true;
					cout << "GAME Over" << endl;
				}
			}
			break;
		case'w':y--;
			
			if (y == 0 || y == 20)
			{
				if (y == 0)y = 19;
				else y = 1;
			}
			for (int i = 0; i < tail_length; i++)
			{
				if (x == tailx[i] && y == taily[i])
				{
					gameover = true;
					cout << "GAME Over" << endl;
				}
			}
			break;
		case's':
			y++;
			
			if (y == 0 || y == 20)
			{
				if (y == 0)y = 19;
				else y = 1;
			}
			for (int i = 0; i < tail_length; i++)
			{
				if (x == tailx[i] && y == taily[i])
				{
					gameover = true;
					cout << "GAME Over" << endl;
				}
			}
			break;
		case'd':
			x++;
			
			if (x == 0 || x == 30)
			{
				if (x == 0)x = 29;
				else x = 1;
			}
			for (int i = 0; i < tail_length; i++)
			{
				if (x == tailx[i] && y == taily[i])
				{
					gameover = true;
					cout << "GAME Over" << endl;
					
				}
			}
			break;
		default:
			
			break;
		}

	}
	
}


void input2()
{
	if (_kbhit)
	{
		switch (_getch())
		{
		case'a':
			x--;

			if (x == 0 || x == 30||y==0||y==20)
			{
				gameover = true;
				cout << "GAME Over" << endl;
			}
			
			
			break;
		case'w':y--;

			if (x == 0 || x == 30 || y == 0 || y == 20)
			{
				gameover = true;
				cout << "GAME Over" << endl;
			}
			break;
		case's':
			y++;

			if (x == 0 || x == 30 || y == 0 || y == 20)
			{
				gameover = true;
				cout << "GAME Over" << endl;
			}
			break;
		case'd':
			x++;

			if (x == 0 || x == 30 || y == 0 || y == 20)
			{
				gameover = true;
				cout << "GAME Over" << endl;
			}
			break;
		default:

			break;
		}

	}

}

void never_touch_your_self()
{
	while (!gameover){
		system("cls");
		for (int i = 0; i < width; i++)
		{
			if (i == 0 || i == width - 1)
			{
				for (int j = 0; j < width; j++)
				{
					cout << "#";
				}
				if (i == 0)
					for (int n = 0; n < height; n++)
					{

					cout << "#";
					for (int j = 0; j < width; j++)
					{
						if (n == y&&j == x){
							cout << "O";


						}

						else if (foody == n&&foodx == j){
							if (bigfood < 5)
								cout << "*";
							else{
								cout << "@";
							}
						}

						else {
							space = false;
							for (int t = 0; t < tail_length; t++)
							{
								if (tailx[t] == j&&taily[t] == n){
									cout << "o";
									space = true;
								}

							}
							if (!space)
								cout << " ";
						}


					}
					if (n != 0)cout << "#";
					cout << endl;


					}

			}


		}

		if (x == foodx&&y == foody)
		{
			tail_length++;






			if (bigfood < 5)
				score += 5;
			else{
				score += 20;
				bigfood = -1;
			}
			bigfood++;
			foodx = rand() % width;
			foody = rand() % height;

			if (foodx > 0 && foody > 0){ inrange = true; }
			while (!inrange)
			{
				foodx = rand() % height;
				foody = rand() % width;
				if (foodx > 0 && foody > 0){ inrange = true; }
			}
		}
		cout << endl;
		cout << "Score =" << score << endl;
		lastx = tailx[0];
		lasty = taily[0];
		tailx[0] = x;
		taily[0] = y;
		for (int pp = 1; pp < tail_length; pp++)
		{
			tempx = tailx[pp];
			tempy = taily[pp];
			tailx[pp] = lastx;
			taily[pp] = lasty;
			lastx = tempx;
			lasty = tempy;

		}
		input();
		
	}
}

void never_touch_walls(){

	while (!gameover){
		system("cls");
		for (int i = 0; i < width; i++)
		{
			if (i == 0 || i == width - 1)
			{
				for (int j = 0; j < width; j++)
				{
					cout << "#";
				}
				if (i == 0)
					for (int n = 0; n < height; n++)
					{

					cout << "#";
					for (int j = 0; j < width; j++)
					{
						if (n == y&&j == x){
							cout << "O";


						}

						else if (foody == n&&foodx == j){
							if (bigfood < 5)
								cout << "*";
							else{
								cout << "@";
							}
						}

						else {
							space = false;
							for (int t = 0; t < tail_length; t++)
							{
								if (tailx[t] == j&&taily[t] == n){
									cout << "o";
									space = true;
								}

							}
							if (!space)
								cout << " ";
						}


					}
					if (n != 0)cout << "#";
					cout << endl;


					}

			}


		}

		if (x == foodx&&y == foody)
		{
			tail_length++;






			if (bigfood < 5)
				score += 5;
			else{
				score += 20;
				bigfood = -1;
			}
			bigfood++;
			foodx = rand() % width;
			foody = rand() % height;

			if (foodx > 0 && foody > 0){ inrange = true; }
			while (!inrange)
			{
				foodx = rand() % height;
				foody = rand() % width;
				if (foodx > 0 && foody > 0){ inrange = true; }
			}
		}
		cout << endl;
		cout << "Score =" << score << endl;
		lastx = tailx[0];
		lasty = taily[0];
		tailx[0] = x;
		taily[0] = y;
		for (int pp = 1; pp < tail_length; pp++)
		{
			tempx = tailx[pp];
			tempy = taily[pp];
			tailx[pp] = lastx;
			taily[pp] = lasty;
			lastx = tempx;
			lasty = tempy;

		}
		input2();
		
	}

}
void welcoming()
{
	cout << "Enter Your Name : ";
	
	cin >> player_name;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t*****************************************************************************************\n";
	cout << "\t\t\t**********  WELCOME\t" << player_name <<"\t TO ' SNAKE ' Game ***********\n";
	cout << "\t\t*****************************************************************************************\n";
	Sleep(2000);
	cout << endl << endl<<endl;
	while (choice_level != 1 && choice_level != 2)
	{
		cout << "enter 1 to choice reverse wall level " << endl;
		cout << endl;
		cout << "enter 2 to choice never touch walls " << endl;
		cin >> choice_level;
		system("cls");
	}
}


int  main()
{
	welcoming();
	if (choice_level == 1){ never_touch_your_self(); }
	else{ never_touch_walls(); }



	system("pause");
	return 0;
}