#include "Game_Actor.h"
using namespace std;

Game_Actor::Game_Actor(int sChar_Code, int sColor_Code, int sX, int sY,int sPoints):
	Char_Code(sChar_Code), Color_Code(sColor_Code),Points(sPoints)
{
	coord.X = sX; 
	coord.Y = sY; 
	isAlive = true;
}

void Game_Actor::moveTo(int x, int y) {
	hide();
	coord.X = x;
	coord.Y = y;
	show();
}

int Game_Actor::kill() {
	isAlive = false;
	hide();
	return(Points);
}

void Game_Actor::hide() const
{
	UIKit::gotoXY(coord.X, coord.Y);
	cout << " ";
}

void Game_Actor::show() const
{
	UIKit::gotoXY(coord.X, coord.Y);
	UIKit::color(Color_Code);
	cout << char(Char_Code);
}

Game_Actor::~Game_Actor()
{
}



