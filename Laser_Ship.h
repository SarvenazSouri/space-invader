#pragma once
#include "Game_Actor.h"

/**
* Lasers shot from the ship, moving up the screen
* child of Game_Actor class
*/
class Laser_Ship :public Game_Actor {
public:
	Laser_Ship(int x, int y); // constructor
	void restart(int x, int y);
	void move();
};
