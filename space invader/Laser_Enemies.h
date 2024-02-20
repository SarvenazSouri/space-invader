#pragma once
#include "Game_Actor.h"

/**
* Lasers coming down from ennemies
* child of Game_Actor class
*/
class Laser_Enemies :public Game_Actor {
public:
	Laser_Enemies(int x, int y); // constructor
	void restart(int x, int y);  // revive a laser
	void move();
};