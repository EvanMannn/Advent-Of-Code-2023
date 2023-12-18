#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<string> winningNumbers;
vector<string> elfsNumbers;





int calculateMatches(string winningNums, string elfNums)
{
	int matches = 0;
	int k = 1;
	while (k < elfNums.length())
	{
		string num = elfNums.substr(k, 2);
		num += " ";
		if (winningNums.find(num) != string::npos)
		{
			matches++;
		}
		k += 3;
	}
	return matches;
}


int findMatchesForIndexs(long int totalMatches, vector<int> indexes)
{
	int iterationMatches = 0;
	for (int i = 0; i < indexes.size(); i++)
	{
		vector<int> newIndexes;

		iterationMatches = calculateMatches(winningNumbers[indexes[i]], elfsNumbers[indexes[i]]);
		totalMatches += iterationMatches;
		for (int j = 1; j <= iterationMatches; j++)
			newIndexes.push_back(indexes[i] + j);



		totalMatches = findMatchesForIndexs(totalMatches, newIndexes);
	}

	return totalMatches;

}

int main(void)
{
	ifstream inputFile("day4_PuzzleInput.txt");



	winningNumbers.resize(186);
	elfsNumbers.resize(186);

	string temp;

	for (int i = 0; i < 186; i++)
	{
		getline(inputFile, temp, ':');
		getline(inputFile, winningNumbers[i], '|');
		getline(inputFile, elfsNumbers[i]);
	}

	long int totalMatches = 0;

	for (int j = 0; j < 186; j++)
	{
		vector<int> vect(1, j);
		totalMatches = findMatchesForIndexs(totalMatches, vect);
	}

	cout << "The answer to day 4 part 2 is : " << totalMatches + 186;

	return 0;

}