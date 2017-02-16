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
��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0
��������:
����һ���ַ���,����������ĸ����,����Ϊ��

�������:
����ǺϷ�����ֵ����򷵻ظ����֣����򷵻�0
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