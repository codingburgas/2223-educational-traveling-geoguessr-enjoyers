#include <iostream>
#include <iomanip>
#include <thread>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <fstream>

#include "header/colorSelection.h"
#include "header/gotoxy.h"
#include "header/logo.h"
#include "header/germany.h"
#include "header/eiffelTower.h"
#include "header/bulgaria.h"
#include "header/germanyQuestion1.h"
#include "header/germanyQuestion2.h"

using namespace std;

enum
{
	BLACK = 0,
	RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
	YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
	WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
};

WORD displayColor[] = { WHITE, WHITE };

const int xStartPosition = 50;

void mainMenu()
{
	Logo();

	int counter = 1;
	char key;

	while (true)
	{
		if (counter >= 1 && counter <= 4)
			displayColor[counter - 1] = RED;

		gotoxy(52, 11);
		colorSelection(displayColor[0]);
		cout << "1. Start";

		gotoxy(52, 12);
		colorSelection(displayColor[1]);
		cout << "2. Exit";

		key = _getch();

		if (key == 80 && (counter >= 1 && counter <= 1)) // 80 - down arrow (keyboard)
			counter++;
		if (key == 72 && (counter >= 2 && counter <= 3)) // 72 - up arrow (keyboard)
			counter--;

		//carriage return - enter (keyboard)
		if (key == '\r')
		{
			for (int i = 0; i < 2; i++)
				displayColor[i] = WHITE;

			system("CLS");

			if (counter == 1)
			{

				break;
			}

			else if (counter == 2)
			{
				exit(EXIT_SUCCESS);
			}
		}
		for (int i = 0; i < 2; i++)
			displayColor[i] = WHITE;
	}
}

void game()
{
	string name;
	int choice;
	int money = 200;
	int score = 0;
	float multiplier = 0;
	
	cout << "Hello, player! Please enter your name below!" << endl << endl;
	
	cin >> name;
	cout << endl;

	system("cls");

	cout << "Nice to meet you, " << name << "!" << endl;
	cout << "Hope you have fun while playing this!" << endl << endl;
	cout << "Press enter to continue";

	Sleep(1000);

	int key = _getch();
	system("cls");

	cout << "After saving up enough money, you decide to explore different countries in Europe." << endl << endl;
	Sleep(1000);
	cout << "You will visit some of the most popular monuments in the country and " << endl; 
	cout << "you will be asked historical and geographical questions about the country." << endl << endl;
	Sleep(1000);
	cout << "Answer it right and you will get points. If you manage to answer the " << endl;
	cout << "second question(it is going to be a difficult one), you will get bonus points." << endl << endl;
	Sleep(1000);
	cout << "Try to achieve the most points and win." << endl << endl;
	cout << "Press enter to continue";
	Sleep(1000);
	
	key = _getch();
	system("cls");

	cout << "Your starting point is Bulgaria." << endl << endl;
	cout << "Your first destination is Germany. How are you going to get there?" << endl << endl;
	cout << "1. Train(100$ 1.5x score)   2. Car (150$ 2x score)   3. Airplane (50$, no multiplier)" << endl << endl;
	cout << "Your balance: " << money << endl;

	cin >> choice;

	if (choice == 1)
	{
		multiplier += 1.5;
	}
	else if (choice == 2)
	{
		multiplier += 2;
	}
	else if (choice == 3)
	{
		multiplier += 1;
	}

	system("cls");

	cout << "Welcome to Germany!";
	germany();

	cout << "You arrive in Berlin, eager to begin your trip around Europe. Here's the first question!" << endl << endl;
	cout << "Continue" << endl;

	key = _getch();
	system("cls");

	germanyQuestion1();

	cout << "Your score: " << score * multiplier << " " << multiplier << "x" << endl << endl;

	key = _getch();

	if (key == 'A' || key == 'a')
	{
		money += 10;
		score += 100;

		cout << "Correct!";

		Sleep(1000);
		system("cls");

		cout << "Nice one! But can you get this bonus question right?" << endl << endl;
			
		germanyQuestion2();

		cout << "Your score: " << score * multiplier << " " << multiplier << "x" << endl << endl;

		key = _getch();

		if (key == 'A' || key == 'a')
		{
			money += 20;
			score += 400;

			cout << "Correct!";

			Sleep(1000);
			system("cls");
		}
			
	}
	else
	{
		cout << "Wrong!";

		Sleep(1000);
		system("cls");

		cout << "Oof. That's okay, try this one!" << endl << endl;
			
		germanyQuestion2();

		key = _getch();

		if (key == 'A' || key == 'a')
		{
			money += 20;
			score += 400;

			cout << "Correct!";

			Sleep(1000);
			system("cls");
		}
	}
}
	



int main()
{
	mainMenu();

	game();

	
}
