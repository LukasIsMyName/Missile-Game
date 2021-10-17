//Author: Lukas Sumkauskas
//
//ID: C00263149
//Date: 2021 October
//Estimated time: 5 hours
//Time taken: 1.3h + 
//Error: 

#include <iostream>

//An easier way to initialize multiple gamestate variables
enum class GameState 
{
	CoordinatePick,
	WarheadPick,
	Scanning,
	CodeInsert,
	Shooting,
	Exit
};

enum class MissileHead 
{
	Explosive,
	PewPew,
	Atomic
};

//Missile structure
struct missile 
{



};


struct Welcome 
{
	void initialize();
};

struct User
{
	//User data variables
	int x = 0;
	int y = 0;
	int warHead = 0;
	int m_score = 0;
	
	void inputCoordinates();
	void chooseWarhead();
	bool scanMap();

};

//Map structure
struct map
{
	//A Map array of size 10x10
	int map_array[10][10] = {
		{0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		{0, 1, 1, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
	};
};

//This is where the magic happens!
int main()
{
	//Object declarations
	Welcome message;
	User player;
	GameState state{GameState::CoordinatePick};

	//Simple game loop
	switch (state)
	{
	case GameState::CoordinatePick:
		message.initialize();//Creating text in a separate struct saves main from having trash code
		player.inputCoordinates(); //Waits for the user to enter the coordinates and/or choose an option from the menu
		state = GameState::WarheadPick;
		break;
	case GameState::WarheadPick:
		player.chooseWarhead(); // Waits for the user to choose the warhead
		state = GameState::Scanning;
		break;
	case GameState::Scanning:
		player.scanMap(); // Scans the map using the coordinates user has given
		if (!player.scanMap())
		{
			state = GameState::CoordinatePick;
		}
		else
		{
			state = GameState::CodeInsert;
		}
		break;
	case GameState::CodeInsert:
		break;
	case GameState::Shooting:
		break;
	case GameState::Exit:
		break;
	default:
		break;
	}


	//Misc
	system("Pause");
	return 0;
}

/// <summary>
/// Function displaying base information about the game
/// </summary>
void Welcome::initialize()
{
	//Declaration of a string array and build
	std::string message[9];
	message[0] = "                  - - - - - - Welcome to PewPew text game! - - - - - - \n";
	message[1] = "- - - To interact with the game, read the text below and press according keys! - - -\n";
	message[2] = " #0 - Exit the game - - - -\n";
	message[4] = " #1 - Scan for enemies - - - -\n";
	message[5] = " #2 - Choose missile type - - - -\n";
	message[6] = " #3 - Display launch code - - - -\n";
	message[7] = " #4 - Launch missile - - - -\n";
	message[8] = "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";

	//For loop to print out each cell of the string array
	for (int i = 0; i < 9; i++)
	{
		std::cout << message[i];
	}
}

/// <summary>
/// Takes user input for coordinates
/// </summary>
void User::inputCoordinates()
{
	//Declaration of a string array and build
	std::string message[2];
	message[0] = "       -- Please enter the coordinates down below, you wish to strike --\n";
	message[1] = "(Make sure you type in X first and then press spacebar to type in Y coordinates)\n";
	for (int i = 0; i < 2; i++) //For loop to print out each cell of the array
	{
		std::cout << message[i];
	}
	std::cin >> x >> y;

}

/// <summary>
/// User decides which warhead they want on their missile by input
/// </summary>
void User::chooseWarhead()
{
	//Declaration of a string array and build
	std::string message[4];
	message[0] = "       -- Please choose which warhead you want to use on your missile --\n\n";
	message[1] = " #1 - Explosive - - - -\n";
	message[2] = " #2 - Atomic - - - -\n";
	message[3] = " #3 - PewPew - - - -\n";
	for (int i = 0; i < 4; i++) //For loop to print out each cell of the array
	{
		std::cout << message[i];
	}
	std::cin >> warHead; //Takes user input and assigns the number
}

/// <summary>
/// Function that scans for possible enemies at the coordinates
/// </summary>
bool User::scanMap()
{
	std::string messageRedLight[2];
	std::string messageGreenLight[2];
	bool valid = true;

	messageRedLight[0] = "- There seems to be a vast land, where you are aiming! Maybe your coordinates were too big?\n";
	messageRedLight[1] = "       (Try typing in the coordinates in the range of 1 to 10, maybe that will help?)\n";

	messageGreenLight[0] = "- Coordinates are valid, we are ready to launch an attack\n";
	messageGreenLight[1] = "- Launch the missile?\n";

	//If statements to catch if the coordinates fit the array
	if (x > 10 || y > 10)
	{
		for (int i = 0; i < 2; i++)
		{
			std::cout << messageRedLight[i];
			valid = false;
		}
	}
	//Valid coordinates
	if (x <= 10 || y <= 10)
	{
		for (int i = 0; i < 2; i++)
		{
			messageGreenLight[i];
			valid = true;
		}
	}
	return valid;
}
