#pragma once
#ifndef _Guard_Class_//makes sure it is compiled only once
#define _Guard_Class_

#include <cmath>//math library
//#include game time
#include "Movement.h"

class Guard {
private:
	int angle;//angle between the line of look and north of the map (line of look
	int location[2];//current location of the guard
	int pace;//how fast the guard walks


public:
	int patrol(int amount,int locations[][2]); //takes an array with list of points to go to 
	//int check_noise(int noiseLocation[2]); //takes location of where noise took place and investigates
	int rotate(int destination[2]); //rotates the guard to face the destination
	Guard(int initialLocation[2], int angle, int pace);//creates guard, taking what location he starts in




};





#endif // !_Guard_Class_