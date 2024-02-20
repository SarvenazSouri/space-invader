#pragma once

#include "UIKit.h"
#include "Game_Actor.h"

/**
* The ship at the bottom of the screen
* child of Game_Actor class
*/
class Ship : public Game_Actor
{
public:
	Ship();
	void move(char key_pressed); // k move right, l move left
	void move(); // just because it is required, won't be used
};
