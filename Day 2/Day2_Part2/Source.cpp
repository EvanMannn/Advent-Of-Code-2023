#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

int checkGames(string fileName)
{
	int sumOfPowers = 0, gamePower = 0;

	string fileLine, fileLineSeg, randomSelection, cubeSelection;

	ifstream inputFile(fileName);

	for (int i = 1; i < 101; i++)
	{
		int maxBlue = 0, maxGreen = 0, maxRed = 0;

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
					if (stoi(count) > maxGreen)
						maxGreen = stoi(count);

				if (cubeColour == "blue")
					if (stoi(count) > maxBlue)
						maxBlue = stoi(count);

				if (cubeColour == "red")
					if (stoi(count) > maxRed)
						maxRed = stoi(count);


			}
		}
		gamePower = maxGreen * maxBlue * maxRed;

		sumOfPowers += gamePower;
	}

	return sumOfPowers;
}

int main(void)
{
	int answer = checkGames("day2_PuzzleInput.txt");
	cout << "The answer to day two part 2 is: " << answer;
	return 0;
}