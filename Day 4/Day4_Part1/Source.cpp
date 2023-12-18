#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
	ifstream inputFile("day4_PuzzleInput.txt");

	vector<string> winningNumbers;
	vector<string> elfsNumbers;

	winningNumbers.resize(186);
	elfsNumbers.resize(186);

	string temp;

	for (int i = 0; i < 186; i++)
	{
		getline(inputFile, temp, ':');
		getline(inputFile, winningNumbers[i], '|');
		getline(inputFile, elfsNumbers[i]);
	}

	int points = 0;

	for (int j = 0; j < 186; j++)
	{
		int numWinningNumbers = 0;
		int k = 1;
		while (k < elfsNumbers[j].length())
		{
			string num = elfsNumbers[j].substr(k, 2);
			num += " ";
			if (winningNumbers[j].find(num) != string::npos)
			{
				numWinningNumbers++;
			}
			k += 3;
		}

		if (numWinningNumbers != 0)
			points += (pow(2, numWinningNumbers - 1));
	}

	cout << "The answer to day 4 part 1 is : " << points;

	return 0;

}