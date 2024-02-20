#include "Laser_Enemies.h"

Laser_Enemies::Laser_Enemies(int x, int y)
	:Game_Actor(33, 10,x,y,0)
{
	// character 33
	// color = 10 green color, high intensity
	show();
}

void Laser_Enemies::restart(int x, int y)
{
	coord.X = x;  // column where to start
	coord.Y = y;  // row where to start
	isAlive = true;
	show();
}

void Laser_Enemies::move()
{
	// enemy lasers move down the screen
	// if not reached the bottom of the screen, move down
	if (coord.Y < 41)
	{
		moveTo(coord.X, coord.Y + 1); // move down
	}
	// if laser reached bottom of screen kill hit
	else kill();
}