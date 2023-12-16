#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;


int calculate_calibration_part1(string puzzleInputFileName)
{
	int sum = 0;

	string fileLine;
	string firstDigit, lastDigit;

	ifstream inputFile(puzzleInputFileName);

	while (getline(inputFile, fileLine))
	{
		firstDigit = string(1, fileLine[fileLine.find_first_of("0123456789")]);
		lastDigit = string(1, fileLine[fileLine.find_last_of("0123456789")]);
		sum += stoi(firstDigit + lastDigit);
	}

	return sum;
}


int main(void)
{
	int part1_answer = calculate_calibration_part1(string("day1PuzzleInput.txt"));

	cout << "The answer to part 1 is: " << part1_answer;

	return 0;
}