#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

map<string, string> s_to_num
{
	{"one", "1"},
	{"two", "2"},
	{"three", "3"},
	{"four", "4"},
	{"five", "5"},
	{"six", "6"},
	{"seven", "7"},
	{"eight", "8"},
	{"nine", "9"},
	{"zero", "0"}
};



int calculate_calibration_part2(string puzzleInputFileName)
{
	int sum = 0;

	

	string lowestWord, highestWord;

	string fileLine;

	ifstream inputFile(puzzleInputFileName);
	while (getline(inputFile, fileLine))
	{
		int lowestIdx = 100000000, highestIdx = -1;
		for (auto item : s_to_num)
		{
			int lowIdx = fileLine.find(item.first);
			int highIdx = fileLine.rfind(item.first);

			if (lowIdx < lowestIdx && lowIdx != string::npos)
			{
				lowestIdx = lowIdx;
				lowestWord = item.first;
			}

			if (highIdx > highestIdx && highIdx != string::npos)
			{
				highestIdx = highIdx;
				highestWord = item.first;
			}
		}
		
		if (lowestIdx != 100000000)
			fileLine.insert(lowestIdx, s_to_num[lowestWord]);
		if (highestIdx != -1)
			fileLine.insert(highestIdx + highestWord.length(), s_to_num[highestWord]);

		string firstDigit = string(1, fileLine[fileLine.find_first_of("0123456789")]);
		string lastDigit = string(1, fileLine[fileLine.find_last_of("0123456789")]);

		sum += stoi(firstDigit + lastDigit);
	}


	

	return sum;
}




int main(void)
{
	int part2_answer = calculate_calibration_part2(string("day2PuzzleInput.txt"));
	cout << "The answer to part 2 is: " << part2_answer;

	return 0;
}