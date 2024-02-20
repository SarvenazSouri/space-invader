#pragma once
#include "Game_Actor.h"

/**
* the Ennemy_Fast move across the screen
* child of Game_Actor class
*/
class Enemy_Fast : public Game_Actor {
public:
	Enemy_Fast();
	void move();
private:
	bool direction; // true= move toward the right, false = move toward the left
};