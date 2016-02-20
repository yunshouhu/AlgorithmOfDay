
#include<algorithm>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s, s1, s2;
	while (getline(cin, s))
	{
		int flag;
		s1 = "you";
		s2 = "we";
		flag = s.find(s1, 0);
		while (flag != string::npos)
		{
			s.replace(flag, 3, s2);
			flag = s.find(s1, flag + 1);
		}
		cout << s << endl;
	}
	return 0;
}
