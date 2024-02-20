#include "Laser_Ship.h"

Laser_Ship::Laser_Ship(int x, int y)
	: Game_Actor(15, 9, x, y, 0)
{
	// ASCII code 15, 
	// Ship_Laser_Color = 9 blue color, high intensity
	show();
}

void Laser_Ship::restart(int x, int y)
{
	coord.X = x;  // column where to start
	coord.Y = y;   // row where to start
	isAlive = true;
	show();
}

void Laser_Ship::move()
{
	// ship lasers move up the screen
	// if not reached the top of the screen, move up
	if (coord.Y > 1)
	{
		moveTo(coord.X, coord.Y - 1); // move up
	}
	// if laser reached top of screen kill hit
	else kill();
}