#pragma once
#include "UIKit.h"

/**
* Father class for all game actors: ship, lasers, ennemies
* This is an abstract class, see move() function must be implemented in all child classes
*/
class Game_Actor
{
public:
	COORD coord;  // position on screen, see windows.h
	bool isAlive; // if alive it can move and can be killed for points

	// constructor see below for parameters
	Game_Actor(int Char_Code, int Color_Code, int x, int y, int Points);
	~Game_Actor(); // destructor

	// public methods
	void show() const;    // display the character
	int kill();
	virtual void move() = 0; // pure virtual->all child class must implement

protected:
	const int Char_Code;   // ASCII character to display
	const int Color_Code; // color of the character
	const int Points;     // nb of points when killed
	void moveTo(int x, int y); // move to a new position
	void hide() const;    // erase the character
};

