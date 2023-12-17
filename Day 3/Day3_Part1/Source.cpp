#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int sumPartNumbers(string fileName)
{
	vector<vector<char>> engineLayout;
	engineLayout.resize(140);

	string line;

	ifstream inputFile(fileName);

	int lineNum = 0;

	//Formatting the text file into a vector
	while (getline(inputFile, line))
	{
		engineLayout[lineNum].resize(line.length());

		for (int i = 0; i < line.length(); i++)
		{
			char test = line[i];
			engineLayout[lineNum][i] = line[i];
		}

		lineNum += 1;
	}


	

	return 0;
}


int main(void)
{
	sumPartNumbers("day3_PuzzleInput.txt");
	return 0;
}