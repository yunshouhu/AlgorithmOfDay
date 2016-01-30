#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//http://acm.nyist.net/JudgeOnline/problem.php?pid=19
int main()
{
	int n;
	string a = "123456789";
	cin >> n;
	while (n--)
	{
		int n, m;
		cin >> n >> m;
		string output = a.substr(0, m);
		cout << output << endl;

		string::iterator i = a.begin();//迭代器
		while (std::next_permutation(i, i + n))//对"123456789"中 长度为n序列进行全排列 
		{
			if (!(a.substr(0, m) == output))
			{
				output = a.substr(0, m);//输出长度为m的序列
				cout << output << endl;
			}
		}
	}
	return 0;
}

