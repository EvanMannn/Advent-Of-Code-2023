#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

int checkGames(string fileName)
{
	int sumOfValidGames = 0;

	bool validGame;

	string fileLine, fileLineSeg, randomSelection, cubeSelection;

	ifstream inputFile(fileName);

	for (int i = 1; i < 101; i++)
	{
		validGame = true;

		//Skip the line starter that says the game number
		getline(inputFile, fileLineSeg, ':');
		
		//Create a string stream for the current game
		getline(inputFile, fileLine);
		stringstream s(fileLine);
		
		//Loop over each random selection
		while (getline(s, randomSelection, ';'))
		{
			//Turn said random selection into a string stream
			stringstream s2(randomSelection);

			//Loop over each of the counts for each colour of cube
			while (getline(s2, cubeSelection, ','))
			{
				//Remove leading space
				cubeSelection.erase(0, 1);
				string cubeColour, count;

				//Find the substring for the colour
				cubeColour = cubeSelection.substr(cubeSelection.find_first_of(' ') + 1);

				//Find the substring for the count
				count = cubeSelection.substr(0, cubeSelection.find_first_of(' '));
				
				if (cubeColour == "green")
					if (stoi(count) > 13)
						validGame = false;

				if (cubeColour == "blue")
					if (stoi(count) > 14)
						validGame = false;

				if (cubeColour == "red")
					if (stoi(count) > 12)
						validGame = false;
				
			}
		}

		if (validGame)
			sumOfValidGames += i;
	}

	return sumOfValidGames;
}

int main(void)
{
	int answer = checkGames("day2_PuzzleInput.txt");
	cout << "The answer to day two part 1 is: " << answer;
	return 0;
}