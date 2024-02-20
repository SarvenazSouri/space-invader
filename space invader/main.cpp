#include <iostream>
#include "UIKit.h"
#include "Menu.h"
#include "Game.h"

using namespace std;

void Help() {

	system("CLS");
	UIKit::color(11); // couleur jade
	UIKit::gotoXY(50, 10); // colonne 50, ligne 10
	cout << "k -> move left" << endl;
	UIKit::gotoXY(50, 11);
	cout << "l -> move right" << endl;
	UIKit::gotoXY(50, 12);
	cout << "spacebar -> shoot" << endl;
	UIKit::gotoXY(50, 13);
	cout << "h -> pause the game" << endl;
	UIKit::gotoXY(50, 14);
	cout << "e -> exit game" << endl;
	UIKit::gotoXY(50, 15);
	cout << "Kill all enemies to win" << endl;
	system("pause");
	return;
}

int main() {
	int Selection;

	// Create main menu, 3 items, top left corner on line 5, column 8;
	// see Menu.h
	string Choices[] = { "Exit","Help","Play" };
	Menu Main_Menu("Welcome to Space Invaders !", Choices, 3, 5, 50);

	while(true) {
		system("CLS");
		Selection = Main_Menu.displayMenu();
		
		switch (Selection) {
		case 1:
			// end program
			exit(0);

		case 2:
			// display help
			Help();
			break;
		case 3:
			// play the game
			Game new_game;

			int game_result;
			game_result = new_game.Play();

			// ### TODO Better display after game
			//
			system("CLS");
			UIKit::frame(48, 8, 70, 20, 2);
			UIKit::color(11);
			UIKit::gotoXY(50, 10);
			cout << "Your score=" << new_game.getScore() << endl;
			UIKit::gotoXY(50, 11);
			cout << "Your level=" << new_game.getLevel() << endl;

			UIKit::gotoXY(50, 13);
			switch (game_result) {
			case 0:
				cout << "Game Over ! " << endl;
				break;
			case 1:
				cout << "You win !" << endl;
				break;
			case 2:
				cout << "You quit !" << endl;
				break;
			}
			system("pause");
			break;
		}
	}
	return(0);
}