#include "Movement.h"

int walk() {
	location[0] = location[0] * sin(angle) * pace;
	location[1] = location[1] * cos(angle) * pace; //a simple function for the guard to walk
	return 0;
}

int turn(bool c_wise) {
	if (c_wise == true) angle = angle - 5 * M_PI / 180;
	else angle = angle + 5 * M_PI / 180;
}