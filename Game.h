#pragma once
#include "Ship.h"
#include "Laser_Ship.h"
#include "Enemy_Fast.h"
#include "Laser_Enemies.h"


#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */

class Game
{
public:
	int Play(); // return: 0=>Game Over, 1=>You win, 2=>You Quit
	int getScore();
	int getLevel();
	Game(); //constructor
	~Game(); //destructor

private:
	int score;
	int level; // use if doing multiple levels
	bool Game_Paused;

	// game color
	const int Game_Info_Color = 15; // white

	// the Ship
	Ship My_Ship;

	// ship lasers array
	const int Max_Nb_Ship_Lasers = 50;
	Laser_Ship *Ship_Lasers[50]; // array of pointers
	int Nb_ShipLasers; // current number in array

	// enemy lasers array
	const int Max_Nb_Enemy_Lasers = 20;
	Laser_Enemies *Enemy_Lasers[20]; // array of pointers
	int Nb_EnemyLasers; // current number in array

	// ET Enemy_Fast array
	Enemy_Fast *ET_List[10];// array of pointers
	int Nb_ETs; // current number in array
	int ET_Period;// create a new one every ET_Period seconds
	clock_t last_ET_time; // time when the last ennemy was created

	// ### TODO these functions implementation in Game.cpp
	void Ship_Laser_Create();
	void Enemy_Lasers_Move_All();
	bool Check_Ship_Killed();
	void Ship_Lasers_Move_All();
	void ETs_Move_All();
	void Check_ETs_Killed();
	void Enemies_Create();
	void Create_Enemy_Laser(int x, int y);
	int Enemies_Get_Total_Alive();
	bool Enemies_Check_All_Killed();
};

