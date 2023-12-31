#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>


using namespace std;


vector<long long> useAlmanac(vector<long long> startVals, vector<long long> destinationStarts, vector<long long> sourceStarts, vector<long long> lengths)
{
	vector<long long> newVals;
	bool rangeFound = false;

	for (int i = 0; i < startVals.size(); i++)
	{
		for (int j = 0; j < destinationStarts.size(); j++)
		{
			if (startVals[i] >= sourceStarts[j] && startVals[i] < (sourceStarts[j] + lengths[j])) rangeFound = true;
			if (rangeFound)
			{
				newVals.push_back(destinationStarts[j] + (startVals[i] - sourceStarts[j]));
				break;
			}
		}
		if (!rangeFound) newVals.push_back(startVals[i]);
		rangeFound = false;
	}

	return newVals;
}


int main(void)
{
	//*Data Reading*
	ifstream inputFile("day5_PuzzleInput.txt");
	string temp;
	getline(inputFile, temp, ':');
	inputFile.get();


	// Getting the initial seeds
	string seedsString;
	getline(inputFile, seedsString);

	vector<long long> seeds;
	stringstream s1(seedsString);

	while (getline(s1, temp, ' '))
	{
		seeds.push_back(stoll(temp));
	}

	//Turn seeds into ranges based on the prompt
	
	vector<long long> newSeeds;
	/*for (long long i = 0; i < 6; i += 2)
	{
		cout << i << endl;
		for (long long j = seeds[i]; j < seeds[i] + seeds[i + 1]; j++) {
			newSeeds.push_back(j);
		}
	}

	*/

	vector<long long> test1;
	for (int i = 0; i < seeds.size(); i += 2)
		test1.push_back(seeds[i]);

	vector<long long> test2;
	for (int i = 1; i < seeds.size(); i += 2)
		test2.push_back(seeds[i]);


	for (int i = 0; i < test1.size(); i++)
	{
		cout << test1[i] << "  " << test1[i] + test2[i] << endl;
	}

	vector<long long> test3;

	test3.resize(test1.size() + test2.size());

	set_union(
		test1.begin(), test1.end(),
		test2.begin(), test2.end(),
		test3.begin()
	);



	//Get destination, source and length vectors
	vector<long long> destStarts, sourceStarts, lengths;
	bool skipHeader = true;

	while (getline(inputFile, temp))
	{


		if (skipHeader) {
			skipHeader = false;
			continue;
		}

		if (temp == string(0, '\n')) {
			newSeeds = useAlmanac(newSeeds, destStarts, sourceStarts, lengths);
			destStarts.clear(); sourceStarts.clear(), lengths.clear();
			skipHeader = true;
		}

		stringstream s2(temp);
		string num;
		int i = 0;
		while (getline(s2, num, ' '))
		{
			if (i == 0) destStarts.push_back(stoll(num));
			if (i == 1) sourceStarts.push_back(stoll(num));
			if (i == 2) lengths.push_back(stoll(num));
			i++;
		}


	}

	long long lowestLocation = -1;
	for (long long i = 0; i < newSeeds.size(); i++)
	{
		if (lowestLocation == -1) lowestLocation = seeds[i];
		else if (newSeeds[i] < lowestLocation) lowestLocation = seeds[i];
	}

	cout << "A potential answer to day five part 2 is: " << lowestLocation;

	return 0;
}
