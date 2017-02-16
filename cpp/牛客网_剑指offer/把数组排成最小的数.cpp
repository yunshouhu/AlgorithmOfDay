#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <functional>
#include <sstream>
using namespace std;

string intToStr(int a)
{
	stringstream ss;
	ss <<a;
	string s = ss.str();
	return s;
}
bool cmp(int a, int b)
{
	string str_a = intToStr(a);
	string str_b = intToStr(b);
	return str_a + str_b < str_b + str_a;
}

class Solution {
public:

	string PrintMinNumber(vector<int> numbers) {
		string result;
		if (numbers.size() == 0) return "";
		std::sort(numbers.begin(), numbers.end(), cmp);
		for (int i = 0; i < numbers.size(); i++)
		{
			result += intToStr(numbers.at(i));
		}
		return result;
	}
};

/**
把数组排成最小的数
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/
void main()
{
	vector<int> list = { 3,32,321};
	Solution ss;
	cout << ss.PrintMinNumber(list) << endl;
	system("pause");

}