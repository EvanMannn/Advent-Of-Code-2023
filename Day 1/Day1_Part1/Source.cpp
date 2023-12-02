#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

map<string, int> s_to_num
{
	{"one", 1},
	{"two", 2},
	{"three", 3},
	{"four", 4},
	{"five", 5},
	{"six", 6},
	{"seven", 7},
	{"eight", 8},
	{"nine", 9},
	{"zero", 0}
};



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


int calculate_calibration_part2(string puzzleInputFileName)
{
	int sum = 0;

	string fileLine;

	string firstDigit, lastDigit;
	int lowestPos = NULL, highestPos = NULL;
	int firstNum = 0, lastNum = 0;

	ifstream inputFile(puzzleInputFileName);

	int lineNum = 0;

	while (getline(inputFile, fileLine))
	{
		map<string, int>::iterator it = s_to_num.begin();
		while (it != s_to_num.end()) {
			int currentPos = 0;
			while (fileLine.find(it->first, currentPos) != string::npos)
			{
				currentPos = fileLine.find(it->first, currentPos) + it->first.length();
				cout << "found: " << it->first << " in line " << lineNum << endl;
			}
			it++;
		}
		lineNum++;
	}

	return sum;
}






int main(void)
{
	//int part1_answer = calculate_calibration_part1(string("day1PuzzleInput.txt"));

	//cout << "The answer to part 1 is:" << part1_answer;

	int test = calculate_calibration_part2(string("day1PuzzleInput.txt"));

	return 0;
}