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
�������ų���С����
����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��
*/
void main()
{
	vector<int> list = { 3,32,321};
	Solution ss;
	cout << ss.PrintMinNumber(list) << endl;
	system("pause");

}