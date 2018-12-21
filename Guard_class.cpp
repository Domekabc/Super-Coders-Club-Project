#include "Guard_class.h"
#define M_PI 3.14159265358979323846


Guard::Guard(int initialLocation[2], int angle, int pace) {//creates the guard
	location[0] = initialLocation[0];
	location[1] = initialLocation[1];
	this->angle = angle;
	this->pace = pace;
}



int Guard::rotate(int destination[2]) {
	int destinationAngle = arctg((destination[0] - location[0]) / (destination[1] - location[1]));

	for (;;) {
		if ((destinationAngle - angle) > M_PI || -M_PI<(destinationAngle-angle)<0) {
			turn(1);
			//delay//implement proper delay here, will be changed for balance
		}
		else {
			turn(-1);
			//same delay as above
		}
		if ((destinationAngle - angle) <= 5 * M_PI / 360) break;
	}

}

int Guard::patrol(int amount, int locations[][2]) {
	double deltaTime;//insert proper unity time here
	for (int i = 0;; i++) {
		rotate(locations[i]);
		for (;;) {
			walk();
			if (sqrt((location[0] - locations[i][0]) ^ 2 + (location[1] - locations[i][1]) ^ 2) <= (pace*deltaTime))//checks for the distance from target and eventually stops walking
				break;
		}
		if (i == (amount - 1)) i = 0;
	}
}

