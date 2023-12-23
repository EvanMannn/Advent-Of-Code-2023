#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	long long time = 46857582, maxDistance = 208141212571410, low, high, answer;

	low = ceil((-time + sqrtf(pow(time, 2) - (4 * maxDistance))) / -2);
	high = floor((-time - sqrtf(pow(time, 2) - (4 * maxDistance))) / -2);

	answer = (high - low + 1);

	cout << "The answer to day 6 part 1 is: " << answer;

	return 0;
}