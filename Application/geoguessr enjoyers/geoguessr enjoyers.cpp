﻿#include <iostream>
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
#include "header/germanyQuestion1.h"
#include "header/germanyQuestion2.h"
#include "header/franceQuestion1.h"
#include "header/franceQuestion2.h"

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

	transport1:

	cout << "Your starting point is Bulgaria." << endl << endl;
	cout << "Your first destination is Germany. How are you going to get there?" << endl << endl;
	cout << "1. Train(100$ 1.5x score)   2. Car (150$ 2x score)   3. Airplane (50$, no multiplier)" << endl << endl;
	cout << "Your balance: " << money << endl << endl;

	cin >> choice;

	if (choice == 1 && money >= 100)
	{
		multiplier += 1.5;
		money -= 100;
	}
	else if (choice == 2 && money >= 150)
	{
		multiplier += 2;
		money -= 150;
	}
	else if (choice == 3 && money >= 50)
	{
		multiplier += 1;
		money -= 50;
	}
	else
	{
		cout << "Not enough money or wrong input!" << endl;
		Sleep(1000);
		system("cls");

		goto transport1;
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

			germanyNext:

			cout << "Great! Let's keep going." << endl << endl;

			Sleep(1000);

			cout << "While looking around Berlin, you take photos of the famous Brandenburg monument and go sightseeing a bit more." << endl;

			cout << R"(
         o#######o
       o###########o
      o#############o
     #################
     ######  \########o
    '#;^ _^,/---\#####!
    ,` /^_ .-~^~-.__\#
   /    ^\/,,@@@,, ;|
  |      \!!@@@@@!! ^,
 #.    .\; '9@@@P'   ^,
 ###./^ ----,_^^      /@-._
               ^--._,o@@@@@@
                  ^;@@@@@@@@@
                    ^-;@@@@

				
		 )" << '\n';

			cout << "Continue";
			key = _getch();
			system("cls");

			cout << "After a day of fun, you feel tired and spend the night at a nearby hotel. (-10$)" << endl;
			cout << "The next morning you decide it's time to head to France." << endl << endl;

			money -= 10;

			cout << R"(
o(=(=(=(=)=)=)=)o
 !!!!!!}!{!!!!!!                                                ___ 
 !!!!!} | {!!!!!                                               /   \
 !!!!}  |  {!!!!     _!_     ()              ()     _!_       | //  |
 !!!'   |   '!!!    |~@~|    ||______________||    |~@~|      |     |
 ~@~----+----~@~    |___|    |                |    |___|       \___/
 !!!    |    !!!      |      |      ~@@~      |      |       _________
 !!!    |    !!!     ( )     |_______  _______|     ( )     |____-____|
 !!!____|____!!!  __(___)__  {__~@~__}{__~@~__}  __(___)__  |____-____|
 !!!=========!!!   |__-__|   %%%%%%%%%%%%%%%%%%   |__-__|   |____-____|
_!!!_________!!!___|_____|_ %%%%%%%%%%%%%%%%%%%% _|_____|___|____-____|_
                   |     | %%%%%%%%%%%%%%%%%%%%%% |     |   |/       \|
                          %%%%%%%%%%%%%%%%%%%%%%%%
                         %%%%%%%%%%%%%%%%%%%%%%%%%%
                        %%%%%%%%%%%%%%%%%%%%%%%%%%%%
                       /!!!!!!!!!!!!!!!!!!!!!!!!!!!!\
                       !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  
                       !!!!!!!!!!!!!!!!!!!!!!!!!!lc!!
                       `======~@~==========~@~======`
                      `==============================`
                     `====~@~==================~@~====`
                    `==================================`
                   `==~@~==========================~@~==`

		 )" << '\n';

			cout << "Continue";
			key = _getch();
			system("cls");
			
			transport2:

			cout << "How are you going to get there?" << endl << endl;
			cout << "1. Train(100$ 1.5x score)   2. Car (150$ 2x score)   3. Airplane (50$, no multiplier)" << endl << endl;
			cout << "Your balance: " << money << endl << endl;

			cin >> choice;


			if (choice == 1 && money >= 100)
			{
				multiplier += 1.5;
				money -= 100;
			}
			else if (choice == 2 && money >= 150)
			{
				multiplier += 2;
				money -= 150;
			}
			else if (choice == 3 && money >= 50)
			{
				multiplier += 1;
				money -= 50;
			}
			else
			{
				cout << "Not enough money or wrong input!";
				Sleep(1000);
				system("cls");

				goto transport2;
			}

			system("cls");

			cout << "You arrive in Paris and the first thing you see is the Eiffel Tower in front of you." << endl;
			Sleep(1000);
			cout << "Impressed by its size and beauty, you want to learn more about its past and creator." << endl << endl;
			Sleep(1000);

			eiffelTower();

			cout << "Speaking of, here's the first question!" << endl << endl;
			Sleep(1000);

			cout << "Continue";
			
			key = _getch();
			system("cls");

			franceQuestion1();

			cout << "Your score: " << score * multiplier << " " << multiplier << "x" << endl << endl;

			key = _getch();

			if (key == 'B' || key == 'b')
			{
				money += 25;
				score += 200;

				cout << "Correct!";

				Sleep(1000);
				system("cls");

				cout << "Great! Let's see your knowledge about rivers!" << endl << endl;

				franceQuestion2();

				cout << "Your score: " << score * multiplier << " " << multiplier << "x" << endl << endl;

				key = _getch();

				if (key == 'C' || key == 'c')
				{
					money += 40;
					score += 500;
					
					cout << "Correct!";
					Sleep(1000);
					system("cls");

					franceNext:

					cout << "Let's look around Paris a bit more." << endl;
					Sleep(1000);
					cout << "Here's the Arc de Triomphe, another famous Parisian monument!" << endl;
					Sleep(1000);

					cout << R"(
                                ..........,'RRRRRRRRRRRRRRRRRRRRRRRRR`,..........
     1^?##-------##-------##-------##-------##-------##-------##-------##-------##-------##-------##-------##1
     1                                                                                                     1
  -------------------------------------------------------------------------------------------------------------
   ===========================================================================================================
     1!!1 ' ` 1!!1 ' ` 1!!1 ' ` 1!!1 ' ` 1!!1 ' ` 1!!1 ' ` 1!!1 ' ` 1!!1 ' ` 1!!1 ' ` 1!!1 ' ` 1!!1 ' ` 1!!1
     1!!1 ` ' 1!!1 ` ' 1!!1 ` ' 1!!1 ` ' 1!!1 ` ' 1!!1 ` ' 1!!1 ` ' 1!!1 ` ' 1!!1 ` ' 1!!1 ` ' 1!!1 ` ' 1!!1
     1!!1     1!!1     1!!1     1!!1     1!!1     1!!1     1!!1     1!!1     1!!1     1!!1     1!!1     1!!1
    :1  1     1  1     1  1     1  1     1  1     1  1     1  1     1  1     1  1     1  1     1  1     1  1:
    :1  1     1  1     1  1     1  1     1  1     1  1     1  1     1  1     1  1     1  1     1  1     1  1:
    +-------------------------------------------------------------------------------------------------------+
    1                                                                                                       1
=================================================================================================================
\   U       U       U       U       U       U       U       U       U       U       U       U       U       U   /
 ---------------------------------------------------------------------------------------------------------------
    1U  U  U  U  U  U  U  U  U  U  U  U  U  U  U  U  U  U  U  U  U  U  U  U  U  U  U  U  U  U  U  U  U  U  U1
    1  ..  .   . .   . . .   .  .   .  .  .   .  .  . .  . . .  .  . .  . .  . .  . .  .   . .   .  .  .   .1
    1 . . .  .  . . . .    . .    .  .   . .    .  . .   . . .  .  .  . .  .. .  . .  .  .. . . .  . ..  .  1
    1 ..   .    .  .   . .   . .   . .    .    .  .  .    .  .  . . .  .  .  . .  .   . .   .  . .  .  .  . 1
    :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    ---------------------------------------------------------------------------------------------------------
    -------------------------------------------------   -   -------------------------------------------------
    1                                1  .^.....      `:   :'      .....^.  1                                1
    1                                1  :  .-'   ..---! - !---..   `-.  :  1                                1
    1  +-------------------------+   1 .  :   .-'     !   !     `-.   :  . 1   +-------------------------+  1
    1  1 ----------------------- 1   1 . .  .'    .----`-'----.    `.  . . 1   1 ----------------------- 1  1
    1  1 ..   .  .  .   .  .  .  1   1 .. .'   .-'             `-.   `. .. 1   1 .  .  .   .  .  . . ..  1  1
    1  1  . .  . .  .  .   . . . 1   1   :   .'                   `.   :   1   1 . . .. .  .  . .  .     1  1
    1  1 .  . ..  .  .   .    .  1   1  :   '                       `   :  1   1  . .  .  . . .     . .  1  1
    1  1  .      . . . .   . ... 1   1 :   '                         `   : 1   1 .. . . .       . .  .   1  1
    1  1 .  . .      .  . . . .. 1   1.' .'                           `. `.1   1 ..  .   .   .    .  .   1  1
    1  1 ======================= 1    :  '                             `  :    1 ======================= 1  1
    1  +-------------------------+    ' :                               : `    +-------------------------+  1
    1                                !  !                               !  !                                1
    1                                1  1                               1  1                                1
  =========================================                           =========================================
    1                                1  1                               1  1                                1
    1-----------------------------------1                               1-----------------------------------1
    1                                1  1                               1  1                                1
    1                                1  1                               1  1         -.     .' `            1
    1                 ^              1  1                               1  1        ` . . -' : :            1
    1               '                1  1                               1  1         :         ```-..       1
    1        .   . . ^ .````         1  1                               1  1      ---:      O  ```````.     1
    1         .   ..    `````        1  1                               1  1        ``  ``     '`````'      1
    1         . ``   .   '   .       1  1                               1  1         ``             :       1
    1           .  .      . .        1  1                               1  1        :      `    `    >      1
    1        `'   .    `.   :        1  1                               1  1        .  ' '   :`.   :        1
    1         .     '   ..  '        1  1                               1  1                 ---`           1
    1        ' . ' `       ..        1  1                               1  1        `.  .  `.  ,  ..        1
    1         '       ``  -  .       1  1                               1  1        ` `          ..         1
    1        ` '  ^        :'        1  1                               1  1      ` .' .`          `        1
    1        ..  .   ` .   :         1  1                               1  1       `        '  :.  .        1
    1         .  ``. . ``   O        1  1                               1  1        `   -.   . `.           1
    1         `   ::   !    :        1  1                               1  1           .    ' `.  ``        1
    1          :  !!   !  .'         1  1                               1  1           .`.  :  : .'         1
    1          ------------          1  1                               1  1          ------------          1
    1         /            \         1  1                               1  1         /            \         1
    1        ================        1  1                               1  1        ================        1
   ===========1            1==========  1                               1  ==========1            1===========
    1         1            1         1  1                               1  1         1            1         1
    1         1            1         1  1                               1  1         1            1         1
    1         1            1         1  1                               1  1         1            1         1
    1         1            1         1  1                               1  1         1            1         1
    1         1            1         1  1                               1  1         1            1         1
   /---------/--------------\--------\---\                             /---/--------/--------------\---------\
   1         1              1         1  1                             1  1         1              1         1
   1         1              1         1  1                             1  1         1              1         1
   -----------------------------------------------------------------------------------------------------------
		 )" << '\n';

					cout << "Fun fact!" << endl << endl;
					cout << "A giant elephant was almost built in its place! An architect, Charles Ribart had created plans to construct a" << endl;
					cout << "giant elephant named L'elephant Triumphal." << endl;
					cout << "The construction of the elephant was ready to commence, but right before that, the French government changed its" << endl;
					cout << "mind and rejected the plan." << endl << endl;

					cout << "Continue" << endl;
					key = _getch();
					system("cls");

					cout << "Time for some rest, you grab a snack from a nearby cafe and book a room at a hotel (-15$)";
					money -= 15;

					cout << R"(
         {
      {   }
       }_{ __{
    .-{   }   }-.
   (   }     {   )
   |`-.._____..-'|
   |             ;--.
   |            (__  \
   |             | )  )
   |             |/  /
   |             /  /    
   |            (  /
   \             y'
    `-.._____..-'
		 )" << '\n';

					cout << "Continue" << endl;
					key = _getch();
					system("cls");

					transport3:

					cout << "Let's keep going! Now traveling to Spain. But how exactly?" << endl;
					cout << "1. Train(100$ 1.5x score)   2. Car (150$ 2x score)   3. Airplane (50$, no multiplier)" << endl << endl;
					cout << "Your balance: " << money << endl << endl;

					cin >> choice;


					if (choice == 1 && money >= 100)
					{
						multiplier += 1.5;
						money -= 100;
					}
					else if (choice == 2 && money >= 150)
					{
						multiplier += 2;
						money -= 150;
					}
					else if (choice == 3 && money >= 50)
					{
						multiplier += 1;
						money -= 50;
					}
					else
					{
						cout << "Not enough money or wrong input!";
						Sleep(1000);
						system("cls");

						goto transport3;
					}

					system("cls");

					cout << "Welcome to Madrid! Here's the first question!" << endl << endl;

				}

			}
			else
			{
				cout << "Wrong!";

				Sleep(1000);
				system("cls");
				
				cout << "That's okay, how about this one?" << endl << endl;

				franceQuestion2();

				cout << "Your score: " << score * multiplier << " " << multiplier << "x" << endl << endl;

				key = _getch();

				if (key == 'C' || key == 'c')
				{
					money += 20;
					score += 400;

					cout << "Correct!";

					Sleep(1000);
					system("cls");

					goto franceNext;
				}
				else
				{
					cout << "Wrong! Better luck next time!" << endl << endl;
					cout << "Continue";

					key = _getch();
					system("cls");

					goto franceNext;
				}

			}

			

		}
			
	}
	else
	{
		cout << "Wrong!";

		Sleep(1000);
		system("cls");

		cout << "Oof. That's okay, try this bonus question!" << endl << endl;
			
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

			goto germanyNext;
		}
		else
		{
			cout << "Wrong! Better luck next time!" << endl << endl;
			cout << "Continue";
			
			key = _getch();
			system("cls");

			goto germanyNext;
		}
	}
}
	



int main()
{
	
	mainMenu();

	game();

	
}
