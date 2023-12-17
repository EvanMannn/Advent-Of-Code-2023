#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sumPartNumbers(string fileName)
{
	int sumParts = 0;
	bool validNum = false;

	vector<string> engineLayout;
	engineLayout.resize(140);

	string line, strToCheck, strPart1 = "", strPart2 = "", strPart3 = "";

	ifstream inputFile(fileName);

	int lineNum = 0;

	//Formatting the text file into a vector
	while (getline(inputFile, line)) 
	{
		engineLayout[lineNum] = line;
		lineNum += 1;
	}

	//looping over each line in the layout
	for (int i = 0; i < engineLayout.size(); i++)
	{
		strPart1 = "", strPart2 = "", strPart3 = "";

		int numIdx = 0;
		int numLength;
		while (true)
		{
			//finding the index of the number to be checked
			numIdx = engineLayout[i].find_first_of("1234567890", numIdx);
			if (numIdx == string::npos)
				break;

			//finding the length of the number being checked
			numLength = engineLayout[i].find_first_not_of("1234567890", numIdx) - numIdx;

			int curNum = stoi(engineLayout[i].substr(numIdx, numLength));


			if (i > 0)
				strPart1 = engineLayout[i - 1].substr(max(0, numIdx - 1), numLength + 2);

			strPart2 = engineLayout[i].substr(max(0, numIdx - 1), numLength + 2);

			if (i < 139)
				strPart3 = engineLayout[i + 1].substr(max(0, numIdx - 1), numLength + 2);


			strToCheck = strPart1 + strPart2 + strPart3;

			if (strToCheck.find_first_of("*+@#=/-$%&") != string::npos)
				sumParts += curNum;

			numIdx += numLength;
		}
	}
	

	return sumParts;
}


int main(void)
{
	int answer = sumPartNumbers("day3_PuzzleInput.txt");
	cout << "The answer to day 3 part 1 is: " << answer;
	return 0;
}


467..11...*.....35..6