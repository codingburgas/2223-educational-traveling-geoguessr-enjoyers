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
	int money;
	
	cout << "Hello, player! Please enter your name below!" << endl << endl;
	
	cin >> name;
	cout << endl;

	cout << "Nice to meet you, " << name << "!" << endl;
	cout << "Hope you have fun while playing this!" << endl << endl;
	cout << "Press enter to continue";

	Sleep(1000);

	 int key = _getch();
	 system("cls");

	cout << "After saving up enough money, you decide to explore different countries in Europe." << endl;
	Sleep(1000);
	cout << "You will visit some of the most popular monuments in the country and you will be asked a question for the following monument." << endl;
	Sleep(1000);
	cout << "Answer it right and you will get points. If you manage to answer the second question (it is going to be a difficult one), you will get bonus points." << endl;
	Sleep(1000);
	cout << "Try to achieve the most points and win." << endl << endl;
	cout << "Press enter to continue";
	Sleep(1000);
	
	key = _getch();
	system("cls");

	cout << "Your starting point is Bulgaria." << endl << endl;
	
	cout << "Which country will you visit? (Germany - 1; France - 2; Poland - 3; Spain - 4; Italy - 5; Czech Republic - 6; Greece - 7; Romania - 8)" << endl;
	cout << "Enter the number of the country: ";

	cin >> choice;
	system("cls");

	if (choice == 1)
	{
		cout << "Welcome to Germany!";
		germany();

		cout << "You arrive in Berlin, eager to begin your trip around Europe. Here's the first question!" << endl << endl;
		cout << "What currency is used in Germany?" << endl;

		cout << R"(
			  _______________
           _(               ),     ______________   ___________
          (_   A: Euro       _)    _\  B: Lev    _\ (_          )_
            (_______________)_    \_____________\    (_ C: Krone  )_
                            (_)             (_         (___________)
		)" << '\n';

		key = _getch();

		if (key == 'A' || key == 'a')
		{
			cout << "Correct!";
		}
	}
	else if (choice == 2)
	{
		cout << "Welcome to France!";
		eiffelTower();
	}
	else if (choice == 3)
	{
		cout << "Welcome to Poland!";
	}
	else if (choice == 4)
	{
		cout << "Welcome to Spain!";
	}
	else if (choice == 5)
	{
		cout << "Welcome to Italy!";
	}
	else if (choice == 6)
	{
		cout << "Welcome to Czech Republic!";
	}
	else if (choice == 7)
	{
		cout << "Welcome to Greece!";
	}
	else if(choice == 8)
	{
		cout << "Welcome to Romania!";
	}

}

int main()
{
	mainMenu();

	game();

	
}
