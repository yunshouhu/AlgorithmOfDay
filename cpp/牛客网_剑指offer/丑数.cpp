#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <functional>
using namespace std;

class Solution {
public:
	bool isUgly(int number)
	{
		while (number % 2 == 0)
			number /= 2;
		while (number % 3 == 0)
			number /= 3;
		while (number % 5 == 0)
			number /= 5;

		return (number == 1) ? true : false;

	}
	int GetUglyNumber_Solution(int index) {
		if (index <= 0)
			return 0;
		int i = 0;
		int uglyFound = 0;
		while (uglyFound<index)
		{
			i++;
			if (isUgly(i))
			{
				++uglyFound;
			}
			
		}
		return i;
	}
};


void main()
{
	Solution ss;
	cout<<ss.GetUglyNumber_Solution(12) <<endl;
	system("pause");

}