#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	ifstream inputFile("day6_PuzzleInput.txt");

	string times, maxDistances;

	getline(inputFile, times);
	getline(inputFile, maxDistances);

	vector<int> timesVec, maxDistancesVec;

	stringstream s(times);
	string x;
	while (getline(s, x, ' '))
	{
		timesVec.push_back(stoi(x));
	}

	stringstream s2(maxDistances);
	while (getline(s2, x, ' '))
	{
		maxDistancesVec.push_back(stoi(x));
	}

	int answer = 1;

	for (int i = 0; i < maxDistancesVec.size(); i++)
	{
		int low, high;

		low = ceil((-timesVec[i] + sqrtf(pow(timesVec[i], 2) - (4 * maxDistancesVec[i]))) / -2);
		high = floor((-timesVec[i] - sqrtf(pow(timesVec[i], 2) - (4 * maxDistancesVec[i]))) / -2);

		answer *= (high - low + 1);
	}

	cout << "The answer to day 6 part 1 is: " << answer;

	return 0;
}