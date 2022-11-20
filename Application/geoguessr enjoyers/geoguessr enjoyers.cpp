#include <iostream>
#include <iomanip>
#include <thread>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <fstream>

#include "header/colorSelection.h"
#include "header/gotoxy.h"
#include "header/art/logo.h"
#include "header/art/germany.h"
#include "header/art/eiffelTower.h"
#include "header/art/arc.h"
#include "header/art/hotel.h"
#include "header/art/gameOver.h"
#include "header/questions/Germany/germanyQuestion1.h"
#include "header/questions/Germany/germanyQuestion2.h"
#include "header/questions/France/franceQuestion1.h"
#include "header/questions/France/franceQuestion2.h"
#include "header/questions/Spain/spainQuestion1.h"
#include "header/questions/Spain/spainQuestion2.h"
#include "header/questions/Italy/italyQuestion1.h"
#include "header/questions/Italy/italyQuestion2.h"
#include "header/questions/Greece/greeceQuestion1.h"
#include "header/questions/Greece/greeceQuestion2.h"

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
int choice;
int money = 200;
int score = 0;
float multiplier = 0;
char key;

void mainMenu()
{
	Logo();

	int counter = 1;

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

void Germany()
{
	void germanyMap();
    cout << "Welcome to Germany!";

	cout << "You arrive in Berlin, eager to begin your trip around Europe. Here's the first question!" << endl << endl;
	cout << "Continue" << endl;

	key = _getch();
	system("cls");

	germanyQuestion1();

	cout << "Your score: " << score * multiplier << " " << multiplier << "x" << endl << endl;
	cout << "Balance: " << money << endl << endl;

	key = _getch();

	if (key == 'A' || key == 'a')
	{
		money += 20;
		score += 200;

		cout << "Correct!";

		Sleep(1000);
		system("cls");

		germanyNext1:

		cout << "Can you get this bonus question right?" << endl << endl;

		germanyQuestion2();

		cout << "Your score: " << score * multiplier << " " << multiplier << "x" << endl << endl;
		cout << "Balance: " << money << endl << endl;

		key = _getch();

		if (key == 'A' || key == 'a')
		{
			money += 40;
			score += 400;

			cout << "Correct! ";

			Sleep(1000);
			system("cls");

		germanyNext2:

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
		}
		else
		{
			cout << "Wrong!";

			Sleep(1000);
			system("cls");

			goto germanyNext2;
		}
	}
	else
	{
		cout << "Wrong!";

		Sleep(1000);
		system("cls");

		goto germanyNext1;
	}
}

void France()
{
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
	cout << "Balance: " << money << endl << endl;

	key = _getch();

	if (key == 'B' || key == 'b')
	{
		money += 25;
		score += 200;

		cout << "Correct!";

		Sleep(1000);
		system("cls");

	franceNext1:

		cout << "Great! Let's see your knowledge about rivers!" << endl << endl;

		franceQuestion2();

		cout << "Your score: " << score * multiplier << " " << multiplier << "x" << endl << endl;
		cout << "Balance: " << money << endl << endl;

		key = _getch();

		if (key == 'C' || key == 'c')
		{
			money += 40;
			score += 500;

			cout << "Correct!";
			Sleep(1000);
			system("cls");

		franceNext2:

			cout << "Let's look around Paris a bit more." << endl;
			Sleep(1000);
			cout << "Here's the Arc de Triomphe, another famous Parisian monument!" << endl << endl;
			Sleep(1000);

			cout << "Fun fact!" << endl << endl;
			cout << "A giant elephant was almost built in its place! An architect, Charles Ribart" << endl;
			cout << "had created plans to construct a giant elephant named L'elephant Triumphal." << endl;
			Sleep(1000);
			cout << "The construction of the elephant was ready to commence, but right before that," << endl;
			cout << "the French government changed its mind and rejected the plan." << endl << endl;

			cout << "Continue" << endl;
			key = _getch();
			system("cls");

			arc();

			cout << "Continue" << endl;
			key = _getch();
			system("cls");
		}
		else
		{
			cout << "Wrong!";
			Sleep(1000);
			system("cls");

			goto franceNext2;
		}
	}
	else
	{
		cout << "Wrong!";

		Sleep(1000);
		system("cls");

		goto franceNext1;
	}
}

void game()
{
	cout << "Hello, player! Hope you have fun while playing this!";
	cout << endl;

	system("cls");
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
	cout << "1. Train(75$ 1.5x score)   2. Car (100$ 2x score)   3. Airplane (50$, no multiplier)" << endl << endl;
	cout << "Your balance: " << money << endl << endl;

	cin >> choice;

	if (choice == 1 && money >= 100)
	{
		multiplier += 1.5;
		money -= 75;
	}
	else if (choice == 2 && money >= 150)
	{
		multiplier += 2;
		money -= 100;
	}
	else if (choice == 3 && money >= 50)
	{
		money -= 50;
	}
	else
	{
		cout << "Wrong input!" << endl;
		Sleep(1000);
		system("cls");

		goto transport1;
	}

	system("cls");

	Germany();
	
	cout << "After a day of fun, you feel tired and spend the night at a nearby hotel. (-10$)" << endl;
	cout << "The next morning you decide it's time to head to France." << endl << endl;
	money -= 10;
	hotel();

	cout << "Continue";
	key = _getch();
	system("cls");
			
	transport2:

	cout << "How are you going to get there?" << endl << endl;
	cout << "1. Train(75$ 1.5x score)   2. Car (100$ 2x score)   3. Airplane (50$, no multiplier)" << endl << endl;
	cout << "Your balance: " << money << endl << endl;

	cin >> choice;

	if (choice == 1 && money >= 100)
	{
		multiplier += 1.5;
		money -= 75;
	}
	else if (choice == 2 && money >= 150)
	{
		multiplier += 2;
		money -= 100;
	}
	else if (choice == 3 && money >= 50)
	{
		money -= 50;
	}
	else if(money < 50)
	{
		cout << endl;
		cout << "You're out of money and can't progress further!" << endl << endl;

				cout << "Continue";
				key = _getch();
				system("cls");

				gameOver();

				cout << "Score: " << score * multiplier;

				exit(EXIT_SUCCESS);
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
			cout << "Balance: " << money << endl << endl;

			key = _getch();

			if (key == 'B' || key == 'b')
			{
				money += 25;
				score += 200;

				cout << "Correct!";

				Sleep(1000);
				system("cls");

				franceNext1:

				cout << "Great! Let's see your knowledge about rivers!" << endl << endl;

				franceQuestion2();

				cout << "Your score: " << score * multiplier << " " << multiplier << "x" << endl << endl;
				cout << "Balance: " << money << endl << endl;

				key = _getch();

				if (key == 'C' || key == 'c')
				{
					money += 40;
					score += 500;
					
					cout << "Correct!";
					Sleep(1000);
					system("cls");

					franceNext2:

					cout << "Let's look around Paris a bit more." << endl;
					Sleep(1000);
					cout << "Here's the Arc de Triomphe, another famous Parisian monument!" << endl << endl;
					Sleep(1000);

					cout << "Fun fact!" << endl << endl;
					cout << "A giant elephant was almost built in its place! An architect, Charles Ribart" << endl;
					cout << "had created plans to construct a giant elephant named L'elephant Triumphal." << endl;
					Sleep(1000);
					cout << "The construction of the elephant was ready to commence, but right before that," << endl;
					cout << "the French government changed its mind and rejected the plan." << endl << endl;

					cout << "Continue" << endl;
					key = _getch();
					system("cls");

					arc();

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

					cout << "Let's keep going! Now traveling to Spain. But how exactly?" << endl << endl;
					cout << "1. Train(75$ 1.5x score)   2. Car (100$ 2x score)   3. Airplane (50$, no multiplier)" << endl << endl;
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
						money -= 50;
					}
					else if (money < 50)
					{
						cout << endl;
						cout << "You're out of money and can't progress further!" << endl << endl;

						cout << "Continue";
						key = _getch();
						system("cls");

						gameOver();

						cout << "Score: " << score * multiplier;

						exit(EXIT_SUCCESS);
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

					spainQuestion1();

					cout << "Your score: " << score * multiplier << " " << multiplier << "x" << endl << endl;
					cout << "Balance: " << money << endl << endl;

					key = _getch();

					if (key == 'A' || key == 'a')
					{
						money += 50;
						score += 500;

						cout << "Correct!";

						Sleep(1000);
						system("cls");

						spainNext1:

						cout << "Great! Let's see your knowledge about Madrid's culture!" << endl << endl;

						spainQuestion2();

						cout << "Your score: " << score * multiplier << " " << multiplier << "x" << endl << endl;
						cout << "Balance: " << money << endl << endl;

						key = _getch();

						if (key == 'B' || key == 'b')
						{
							money += 60;
							score += 600;

							cout << "Correct!";

							Sleep(1000);
							system("cls");

							spainNext2:

							cout << "Alright! After spending some time looking arond Madrid, it's time to take a nap" << endl;
							cout << "and head for the next stop, Italy!(-20$)" << endl << endl;
							money -= 20;

							cout << "Continue" << endl;
							key = _getch();
							system("cls");

							transport4:

							cout << "Now, how should you travel to Italy ? " << endl << endl;
							cout << "1. Train(75$ 1.5x score)   2. Car (100$ 2x score)   3. Airplane (50$, no multiplier)" << endl << endl;
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
								money -= 50;
							}
							else if (money < 50)
							{
								cout << endl;
								cout << "You're out of money and can't progress further!" << endl << endl;

								cout << "Continue";
								key = _getch();
								system("cls");

								gameOver();

								cout << "Score: " << score * multiplier;

								exit(EXIT_SUCCESS);
							}
							else
							{
								cout << "Not enough money or wrong input!";
								Sleep(1000);
								system("cls");

								goto transport4;
							}

							system("cls");

							cout << "Welcome to Italy! We'll be visiting Rome - Italy's capital and home to one of the most powerful empires in history!" << endl;
							cout << "I bet you can't wait to explore and learn more about it, right?" << endl;

							cout << R"(


▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██████████████████████████████████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██████████████████████████████████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██████████████████████████████████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░    ▓▓████████████████████████████████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓          ████████████████████████████████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                    ████████████████████████
▓▓▓▓▓▓▓▓▓▓  ▓▓▓▓                      ██████████████████████████
▓▓                                    ██████████████████████████
▓▓                                  ████████████████████████████
▓▓▓▓                            ████████████████████████████████
                                ████████████████████████████████
▓▓                              ▓▓██████████████████████████████
▓▓                              ████████████████████████████████
▓▓          ▓▓▓▓                ████████████████████████████████
▓▓▓▓▓▓    ▓▓▓▓▓▓▓▓▓▓              ██████████████████████████████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                ████████████████████████████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                ██████████████████████████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                  ████████████████████████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                ████████████████████████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                ██████████████████████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                ████████████████████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒                      ██████████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                  ████████████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                  ██████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                    ██
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                  
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓          ██████  
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓    ██████  
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓      ██████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓    ██████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  ████████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓    ████████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  ▓▓▓▓▓▓▓▓          ████████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                ████████████████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓          ██████████████████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓      ████████████████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████████████████████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████████████████████
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████████████████████


							)" << endl;

							cout << "Continue";
							key = _getch();
							system("cls");

							italyQuestion1();

							cout << "Your score: " << score * multiplier << " " << multiplier << "x" << endl << endl;
							cout << "Balance: " << money << endl << endl;

							key = _getch();

							if (key == 'C' || key == 'c')
							{
								money += 70;
								score += 700;

								cout << "Correct!";

								Sleep(1000);
								system("cls");

								italyNext1:

								cout << "Here's the bonus question, good luck!" << endl << endl;

								italyQuestion2();

								cout << "Your score: " << score * multiplier << " " << multiplier << "x" << endl << endl;
								cout << "Balance: " << money << endl << endl;

								key = _getch();

								if(key == 'A' || key == 'a')
								{
									money += 85;
									score += 900;
									
									cout << "Correct!";

									Sleep(1000);
									system("cls");

									italyNext2:

									cout << "Great! We should definitely check out the colosseum! Imagine how many" << endl;
									cout << "emperors were changed while it was being built.";
									cout << R"(

			       
              \\||      
             ,'_,-\     
             ;'____\    
             || =\=|    
             ||  - |                               
         ,---'._--''-,,---------.--.----_,         
        / `-._- _--/,,|  ___,,--'--'._<            
       /-._,  `-.__;,,|'                           
      /   ;\      / , ;                            
     /  ,' | _ - ',/, ;
    (  (   |     /, ,,;
     \  \  |     ',,/,;
      \  \ |    /, / ,;
     (| ,^.|   / ,, ,/;
      `-'./ `-._,, ,/,;
           �-._ `-._,,;
           |/,,`-._ `-.
           |, ,;, ,`-._\


									)" << endl;

									cout << "Continue";
									key = _getch();
									system("cls");

									cout << "You go to a nearby restaurant to try traditional Italian spaghetti. Tasty! (-25$)";
									money -= 25;

									cout << R"(

                                                             |||
                                                             |||||,
                                                            \|||||/
                           /)                               `|||||/
                      ,-""//-. ______                       |`"""'|
                   ==|`-.//.-'|,-----'======================|  P  |====
                     |        |---,---,  .---,((--------.   |  A  |
                     |        |  /(_)/  /   (()))` ;'", \   |  S  |
                     `-.____.-' /_  /  /  /| `;',`;; ,/( \  |  T  |
                               /(_)/  /  //  ; ` "  ((()) \ |  A  |
                     .-::-.   /_  /  /  /)   "' ;" ; `;"'  \`-...-'
                    (::::::) /(_)/   `=//==================='  
                     `-::-' /   /     (/
                 ----------'---'
									)" << endl;
									
									cout << "Continue";
									key = _getch();
									system("cls");

									transport5:

									cout << "Next stop, Greece! How should we get there?" << endl << endl;
									cout << "1. Train(75$ 1.5x score)   2. Car (100$ 2x score)   3. Airplane (50$, no multiplier)" << endl << endl;
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
										money -= 50;
									}
									else if (money < 50)
									{
										cout << endl;
										cout << "You're out of money and can't progress further!" << endl << endl;

										cout << "Continue";
										key = _getch();
										system("cls");

										gameOver();

										cout << "Score: " << score * multiplier;

										exit(EXIT_SUCCESS);
									}
									else
									{
										cout << "Not enough money or wrong input!";
										Sleep(1000);
										system("cls");

										goto transport5;
									}

									system("cls");

									cout << "You arrive in Athens, Greece's capital. Astonished by the amount of monuments here, you decide to visit the most popular one." << endl;
									cout << "Standing before the iconic Parthenon, you take some pictures to post in your social media accounts." << endl << endl;
									cout << "Continue";
									key = _getch();
									system("cls");

									greeceQuestion1();
									cout << "Your score: " << score * multiplier << " " << multiplier << "x" << endl << endl;
									cout << "Balance: " << money << endl << endl;

									key = _getch();
									if (key == 'C' || key == 'c')
									{
										money += 80;
										score += 800;

										cout << "Correct!";
										Sleep(1000);
										system("cls");
									}

									greeceNext1:

									cout << "Here's the bonus question, good luck!";
									Sleep(500);
									system("cls");

									greeceQuestion2();
									cout << "Your score: " << score * multiplier << " " << multiplier << "x" << endl << endl;
									cout << "Balance: " << money << endl << endl;

									key = _getch();

									if (key == 'B' || key == 'b')
									{
										money += 100;
										score += 950;

										cout << "Correct!";
										Sleep(1000);
										system("cls");

										greeceNext2:

										cout << "Good job! Your knowledge of the greek mythology is amazing!" << endl;
										cout << "You also visit the monument of the Alexander The Great - one of the most powerful leaders ever." << endl;
										cout << R"(                
														[]|    (______
														[]|__ /       \
														||   \________/
														||      ___
														||     /_  )__
											__|\/)     ||   _/_ \____)
										,----`     \     ||  />=o)
										\_____      \    ||  \]__\
											`--,_/U\  B|\__/===\
												|UUUU\  ||_ _|_\_ \
												|UUUUU\_|[,`_|__|_)
												|UUUUUU\||__/_ __|
												|UUUUUU/-(_\_____/-------,
												/UU/    |H\__\    HHHH|   \\
												|UU/    |H\  |HHHHHHH|    |\\\
												UU      |HH\ \HHHHHHH|    | \\\
												U       |<_\,_\HHHHHH|   /  \\\
												\ (    |HHHHHHHHHHHHH   /  \\\\
												\ \   |=============  /    \\\\\
													\ |             | |
										)";

										transport6:
									}
								}
								else
								{
									cout << "Wrong! ";
									cout << money;

									Sleep(1000);
									system("cls");

									goto italyNext2;
								}
							}
							else
							{
								cout << "Wrong! ";
								cout << money;

								Sleep(1000);
								system("cls");

								goto italyNext1;
							}
						}
						else
						{
							cout << "Wrong!";
							Sleep(1000);
							system("cls");

							goto spainNext2;
						}
					}
					else
					{
						cout << "Wrong!";

						Sleep(1000);
						system("cls");

						goto spainNext1;
					}
				}
				else
				{
					cout << "Wrong!";
					Sleep(1000);
					system("cls");

					goto franceNext2;
				}
			}
			else
			{
				cout << "Wrong!";

				Sleep(1000);
				system("cls");
				
				goto franceNext1;
			}
		}
	



int main()
{
	
	mainMenu();

	game();

	
}
