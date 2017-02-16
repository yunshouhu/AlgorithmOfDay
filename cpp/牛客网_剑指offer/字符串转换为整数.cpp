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
	int StrToInt(string str) {
		int res = 0, n = str.size(), s = 1;
		if (n == 0) return 0;
		if (str[0] == '-')
			s = -1;
		int start = (str[0] == '-' || str[0] == '+') ? 1 : 0;
		for (int i = start; i < n; ++i)
		{
			if (!('0' <= str[i] && str[i] <= '9'))
				return 0;
			res = (res << 1) + (res << 3) + (str[i] & 0xf);//res=res*10+str[i]-'0';
		}
		return res*s;
	}
};
/**
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
输入描述:
输入一个字符串,包括数字字母符号,可以为空

输出描述:
如果是合法的数值表达则返回该数字，否则返回0
https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&tqId=11202&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=3
*/
void main()
{

	Solution s;

	cout << s.StrToInt("1024556") << endl;
	cout << s.StrToInt("+1024556") << endl;

	cout << s.StrToInt("-1024556") << endl;
	cout << s.StrToInt("-d1024556") << endl;

	system("pause");


}