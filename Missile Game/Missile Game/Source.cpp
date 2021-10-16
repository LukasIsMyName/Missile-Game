//Author: Lukas Sumkauskas
//
//ID: C00263149
//Date: 2021 October
//Estimated time: 5 hours
//Time taken:
//Error: 

#include <iostream>

//An easier way to initialize multiple gamestate variables
enum class GameState {
	Play,
	Exit
};

enum class MissileHead {
	Explosive,
	PewPew,
	Atomic
};

//Missile structure
struct missile {



};


//Map structure
struct map
{
	//Map array of 10x10
	int map_array[10][10] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
};

int main()
{

	return 0;
}