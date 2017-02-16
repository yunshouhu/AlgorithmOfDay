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
	//��ϣ����
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
��һ��ֻ����һ�ε��ַ�:
��һ���ַ���(1<=�ַ�������<=10000��ȫ���ɴ�д��ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��
*/
void main()
{
	vector<int> list = { 3, 32, 321 };
	Solution ss;
	cout << ss.FirstNotRepeatingChar("google") << endl;
	system("pause");

}