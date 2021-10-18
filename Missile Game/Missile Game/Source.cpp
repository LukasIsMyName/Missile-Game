//Author: Lukas Sumkauskas
//
//ID: C00263149
//Date: 2021 October
//Estimated time: 5 hours
//Time taken: 1.5h + 2 hours
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
	void exiting();
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
	bool inputCode();

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
	case GameState::WarheadPick:
		player.chooseWarhead(); // Waits for the user to choose the warhead
		state = GameState::Scanning;
	case GameState::Scanning:
		if (!player.scanMap())//If coordinates are bigger than the array
		{
			state = GameState::CoordinatePick;//Change state to coordinate pick
		}
		else
		{
			state = GameState::CodeInsert;
		}
	case GameState::CodeInsert:
		if (player.inputCode()) //If user enters the right code, do this
		{
			state = GameState::Shooting; //Change state from code insert to shooting
		}
		else
		{
			state = GameState::Exit; //Means failed to input code 5 times, therefore exit
		}
	case GameState::Shooting:
		break;
	case GameState::Exit:
		message.exiting();
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
	std::string message[4];
	message[0] = "                  - - - - - - Welcome to PewPew text game! - - - - - - \n";
	message[1] = "- - - To interact with the game, read the text below and press according keys! - - -\n";
	message[2] = " \n";
	message[3] = "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";

	//For loop to print out each cell of the string array
	for (int i = 0; i < 4; i++)
	{
		std::cout << message[i];
	}
}

/// <summary>
/// Small function, that displays exit message after playing the game
/// </summary>
void Welcome::exiting()
{
	std::string message[1];
	message[0] = " *Exiting the game* \n";
	std::cout << message[0];
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
	std::string messageRedLight[3];
	std::string messageGreenLight[3];
	bool valid = false;

	messageRedLight[0] = "- There seems to be a vast land, where you are aiming! Maybe your coordinates were too big?\n";
	messageRedLight[1] = "       (Try typing in the coordinates in the range of 1 to 10, maybe that will help?)\n";
	messageRedLight[2] = " ----------------------------------------------------------------------------------------------- \n";

	messageGreenLight[0] = "- Coordinates are valid, we are ready to launch an attack\n";
	messageGreenLight[1] = "\n";
	messageGreenLight[2] = " ----------------------------------------------------------------------------------------------- \n";

	//If statements to catch if the coordinates fit the array
	if (x > 10 || y > 10)
	{
		for (int i = 0; i < 3; i++)
		{
			std::cout << messageRedLight[i];
			valid = false;
		}
	}
	//Valid coordinates
	if (x <= 10 && y <= 10)
	{
		for (int i = 0; i < 3; i++)
		{
			std::cout << messageGreenLight[i];
			valid = true;
		}
	}

	return valid;
}

/// <summary>
/// Takes user input for missile launch code with simple error checking
/// </summary>
bool User::inputCode()
{
	// 0 for yes 1 for no
	//Variables
	int const YES = 0;
	int input = 0;
	int inputCode = 0;
	bool launch = false;
	int launchCode = 7355608;
	int count = 0; //To keep track, how many times the user has failed to enter the code
	
	//Building up the strings
	std::string message[6];
	message[0] = "   - Enter the launch code below -\n";
	message[1] = "  - Did you forget the launch code? -\n";
	message[2] = "        Yes? #0 --------- No? #1\n";
	message[3] = "      - Please enter the code below -\n"; //Error message
	message[4] = "    - Code incorrect, please try again. -\n"; //Error message
	message[5] = " *You have exceeded the number of times you can enter the code, you have been blocked!*\n"; //Error message
	//String array output
	for (int i = 0; i < 3; i++)
	{
		std::cout << message[i];
	}

	//User input
	std::cin >> input; //If no, do nothing
	if (input == YES) //If user forgot launch code
	{
		std::cout << launchCode;//Output launch code
	}
	std::cout << message[3];
	std::cin >> inputCode;

	//Error checking
	if (inputCode == launchCode)//If launch code matches
	{
		launch = true;//Give launching a green light, i.e set the bool to true
	}
	//Error checking
	if (inputCode != launchCode)
	{
		while (inputCode != launchCode)//Loop while the input doesn't match the actual code
		{
			std::cout << message[4]; //Outputs error message
			inputCode = 0; //Clears the input for another try
			std::cin >> inputCode;
			count++;
			if (count == 4) //If entered incorrectly 5 times
			{
				std::cout << message[5]; //Output error
				launch = false;
				break; //Break out of the loop
			}
		}
	}
	return launch;
}
