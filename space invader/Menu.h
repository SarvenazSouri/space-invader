// 
// Menu class for displaying a menu and returning the user selection
#pragma once

#include <iostream>
using namespace std;
#include <string>
#include <windows.h>	//for Sleep and gotoXY and COORD
#include <conio.h>	//for getch
#include <ctype.h>	//for tolower

class Menu{
public:

	// Initialize the menu. Parameters are:
	// -title : the title written on top
	// -choiceList : the list of options
	// -nbItem : how many options in the list
	// -stratLine : vertical position on the top left corner
	// -stratColumn : horizontal position on the top left corner
	Menu(string title, string* choiceList, int nbItem, int startLine, int startColumn);
	
	// Displays the menu and returns the user selection
	// 1st item is 1 (not 0)
	int displayMenu(); 

	// Move cursor to column x, row y
	void gotoXY(int x, int y);

	~Menu();

private:
	string _title;
	int _nbItem;
	string* _choiceList;
	COORD cornerUL;
	//internal management
	COORD _currentPos;
	COORD _lastPos;
	COORD _firstPos;
	int choice;

protected:
	void move(COORD origin, COORD target);
	int getMaxSize();
	void gotoXY(COORD pos);
	void init();
};
