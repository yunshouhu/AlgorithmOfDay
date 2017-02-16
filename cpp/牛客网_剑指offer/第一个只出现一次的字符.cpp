#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <functional>
#include <sstream>
using namespace std;


class Solution {
public:
	//哈希表法。
	int FirstNotRepeatingChar(string str) {
		if (str.length() == 0)
			return -1;
		char hash[256] = { 0 };
		for (int i = 0; i < str.length(); i++)
		{
			char ch = str[i];
			hash[ch]++;
		}
		for (int i = 0; i < str.length(); i++)
		{
			char ch = str[i];
			if (hash[ch] == 1)
			{
				return i;
			}
		}
		return -1;
	}
};

/**
https://www.nowcoder.com/questionTerminal/1c82e8cf713b4bbeb2a5b31cf5b0417c
第一个只出现一次的字符:
在一个字符串(1<=字符串长度<=10000，全部由大写字母组成)中找到第一个只出现一次的字符,并返回它的位置
*/
void main()
{
	vector<int> list = { 3, 32, 321 };
	Solution ss;
	cout << ss.FirstNotRepeatingChar("google") << endl;
	system("pause");

}