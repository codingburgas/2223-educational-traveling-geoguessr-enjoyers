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
	int money = 20;
	int score = 0;
	
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
	cout << "third question(it is going to be a difficult one), you will get bonus points." << endl << endl;
	Sleep(1000);
	cout << "Try to achieve the most points and win." << endl << endl;
	cout << "Press enter to continue";
	Sleep(1000);
	
	key = _getch();
	system("cls");

	cout << "Your starting point is Bulgaria." << endl << endl;
	
	cout << "Which country will you visit?" << endl << endl;
	cout << "1. Germany  4. Spain    7. Greece" << endl << endl;
	cout << "2. France   5. Italy    8. Romania" << endl << endl;
	cout << "3. Poland   6. Czech Republic" << endl << endl;
	cout << "Enter the number of the country: ";

	cin >> choice;
	system("cls");

	if (choice == 1)
	{
		cout << "Welcome to Germany!";
		germany();

		cout << "You arrive in Berlin, eager to begin your trip around Europe. Here's the first question!" << endl << endl;
		cout << "Continue" << endl;

		key = _getch();
		system("cls");

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
			money += 10;
			score += 100;

			cout << "Correct!";

			Sleep(1000);
			system("cls");

			cout << "Nice one! But can you get this one right?" << endl << endl;
			cout << "What is the capital of Germany?" << endl;

			cout << R"(
	     _______________
           _(               ),     ______________   ___________
          (_   A: Hamburg    _)   _\  B: Berlin  _\ (_          )_
            (_______________)_    \_____________\    (_ C: Bremen )_
                            (_)             (_         (___________)
		)" << '\n';

			key = _getch();

			if (key == 'B' || key == 'b')
			{
				money += 10;
				score += 200;

				cout << "Correct!";

				Sleep(1000);
				system("cls");

				cout << "Here's a bonus question! Good luck!" << endl << endl;
				cout << "Which treaty included a war guilt clause that deemed Germany the aggressor in World War I " << endl;
				cout << "and required it to make reparations ? " << endl;

				cout << R"(
	     _______________
           _(               ),     ______________   ___________
          (_   A: Versailles _)    _\  B: Riga  _\  (_          )_
            (_______________)_    \_____________\    (_ C:Paris  )_
                            (_)             (_         (___________)

				
		)" << '\n';

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
