#include "Enemy_Fast.h"

// constructor ------------------------------------------------
Enemy_Fast::Enemy_Fast()
	: Game_Actor(43, 12,0,0, 50) {
	// Display ASCII character code 43, color code 12
	// 50 points when killed
	coord.X = rand() % 40 + 1; // randomly set the initial position
	coord.Y = rand() % 20 + 1;
	direction = true;
	show();
}

// move function ----------------------------------------------
void Enemy_Fast::move() {

	if (direction) {
		// move toward the right
		moveTo(coord.X + 1, coord.Y); // move right
		if (coord.X == 40) {
			// change direction
			direction = false;
		}
	}
	else {
		// move toward the left
		moveTo(coord.X - 1, coord.Y); // left
		if (coord.X == 1) {
			// change direction
			direction = true;
		}
	}
}