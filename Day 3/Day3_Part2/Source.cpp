#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string digits = "1234567890";

string getNumbersOnRight(string str)
{
	string num;
	string subStr = str.substr(3);
	int i = 0;
	bool digitsFound = false;

	while (true)
	{
		if (digits.find(subStr[i]) != string::npos)
		{
			num.push_back(subStr[i]);
			digitsFound = true;
		}
		else if (digitsFound == true)
		{
			return num;
		}
		i++;
	}
}

string getNumbersOnLeft(string str)
{
	string num;
	string subStr = str.substr(0, 4);
	int i = 3;
	bool digitsFound = false;

	while (true)
	{
		if (i < 0) return num;

		if (digits.find(subStr[i]) != string::npos)
		{
			num.insert(0, string(1, subStr[i]));
			digitsFound = true;
		}
		else if (digitsFound == true)
		{
			return num;
		}
		i--;
	}
}


string getNumbersInMiddle(string str)
{
	string num;
	string subStr = str.substr(2, 3);
	int i = 0;
	bool digitsFound = false;

	while (true)
	{
		if (digits.find(subStr[i]) != string::npos)
		{
			num.push_back(subStr[i]);
			digitsFound = true;
		}
		else if (digitsFound == true)
		{
			return num;
		}
		i++;
	}
}






int sumPartNumbers(string fileName)
{
	int sumGearRatios = 0;

	vector<string> engineLayout;


	engineLayout.resize(140);

	string line, strToCheck, strPart1 = "", strPart2 = "", strPart3 = "", num1, num2;

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

		int gearIdx = 0;

		while (true)
		{
			num1 = "", num2 = "";

			//finding the index of the number to be checked
			gearIdx = engineLayout[i].find_first_of("*", gearIdx);
			if (gearIdx == string::npos)
				break;

			//finding the length of the number being checked
			//numLength = engineLayout[i].find_first_not_of("1234567890", gearIdx) - gearIdx;
			//int curNum = stoi(engineLayout[i].substr(gearIdx, numLength));

			//Top string
			if (i > 0)
				strPart1 = engineLayout[i - 1].substr(max(0, gearIdx - 3), 7);

			//Middle string
			strPart2 = engineLayout[i].substr(max(0, gearIdx - 3), 7);

			//Bottom string
			if (i < 139)
				strPart3 = engineLayout[i + 1].substr(max(0, gearIdx - 3), 7);

			int L, R = string::npos;

			//Find numbers in the top string
			if (strPart1.empty() == false)
			{

				// L and R are the indexes of numbers within the middle three characters of a string part
				// These are used to check if a string part has numbers on the left, right, both, middle or none of the above based on what values they have
				// This dictates which function to use using if statements 
				L = strPart1.substr(2, 3).find_first_of("1234567890");
				R = strPart1.substr(2, 3).find_last_of("12345678990");

				// If there are nno numbers nothing happens for this string
				if (L == string::npos && R == string::npos) {}

				// Check if there are numbers on the right half
				else if ((L == 2 && R == 2) || (L == 1 && R == 2)) 
				{
					if (num1 == "") num1 = getNumbersOnRight(strPart1);
					else if (num2 == "") num2 = getNumbersOnRight(strPart1);

				}

				// Check if there are numbers on the left half
				else if ((L == 0 && R == 0) || (L == 0 && R == 1)) 
				{
					if (num1 == "") num1 = getNumbersOnLeft(strPart1);
					else if (num2 == "") num2 = getNumbersOnLeft(strPart1);
				}

				// Check if there are numbers on the left and right, as well as the middle
				else if (L == 0 && R == 2 && (strPart1.substr(3, 1).find_first_of("1234567890") == string::npos))
				{
					num1 = getNumbersOnRight(strPart1);
					num2 = getNumbersOnLeft(strPart1);
				}

				//If all of those checks failed then the number must be exactly in the middle 
				else 
				{
					if (num1 == "") num1 = getNumbersInMiddle(strPart1);
					else if (num2 == "") num2 = getNumbersInMiddle(strPart1);
				}
			}

			//Find numbers for the middle string
			if (strPart2.empty() == false)
			{
				L = strPart2.substr(2, 3).find_first_of("1234567890");
				R = strPart2.substr(2, 3).find_last_of("12345678990");

				if (L == string::npos && R == string::npos) {}
				else if ((L == 2 && R == 2) || (L == 1 && R == 2))
				{
					if (num1 == "") num1 = getNumbersOnRight(strPart2);
					else if (num2 == "") num2 = getNumbersOnRight(strPart2);

				}
				else if ((L == 0 && R == 0) || (L == 0 && R == 1))
				{
					if (num1 == "") num1 = getNumbersOnLeft(strPart2);
					else if (num2 == "") num2 = getNumbersOnLeft(strPart2);
				}
				else if (L == 0 && R == 2 && (strPart1.substr(3, 1).find_first_of("1234567890") == string::npos))
				{
					num1 = getNumbersOnRight(strPart2);
					num2 = getNumbersOnLeft(strPart2);
				}
				else
				{
					if (num1 == "") num1 = getNumbersInMiddle(strPart2);
					else if (num2 == "") num2 = getNumbersInMiddle(strPart2);
				}
			}

			//Find numbers for the bottom string
			if (strPart3.empty() == false)
			{
				L = strPart3.substr(2, 3).find_first_of("1234567890");
				R = strPart3.substr(2, 3).find_last_of("12345678990");

				if (L == string::npos && R == string::npos) {}
				else if ((L == 2 && R == 2) || (L == 1 && R == 2))
				{
					if (num1 == "") num1 = getNumbersOnRight(strPart3);
					else if (num2 == "") num2 = getNumbersOnRight(strPart3);

				}
				else if ((L == 0 && R == 0) || (L == 0 && R == 1))
				{
					if (num1 == "") num1 = getNumbersOnLeft(strPart3);
					else if (num2 == "") num2 = getNumbersOnLeft(strPart3);
				}
				else if (L == 0 && R == 2 && (strPart3.substr(3, 1).find_first_of("1234567890") == string::npos))
				{
					num1 = getNumbersOnRight(strPart3);
					num2 = getNumbersOnLeft(strPart3);
				}
				else
				{
					if (num1 == "") num1 = getNumbersInMiddle(strPart3);
					else if (num2 == "") num2 = getNumbersInMiddle(strPart3);
				}
			}

			//If two adjacent numbers were found then multiply them and add that value to the total sum of gear ratios
			if (num1 != "" && num2 != "")
				sumGearRatios += (stoi(num1) * stoi(num2));

 			gearIdx += 1;
		}
	}


	return sumGearRatios;
}


int main(void)
{
	int answer = sumPartNumbers("day3_PuzzleInput.txt");
	cout << "The answer to day 3 part 1 is: " << answer;
	return 0;
}


