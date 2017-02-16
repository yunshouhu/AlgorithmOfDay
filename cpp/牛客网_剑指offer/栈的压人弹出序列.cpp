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
	/**
	C++
	模拟堆栈操作：将原数列依次压栈，栈顶元素与所给出栈队列相比，如果相同则出栈，
	如果不同则继续压栈，直到原数列中所有数字压栈完毕。
	检测栈中是否为空，若空，说明出栈队列可由原数列进行栈操作得到。否则，说明出栈队列不能由原数列进行栈操作得到。
	*/
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() == 0)
			return false;
		int j = 0;
		stack<int> ss;
		for (int i = 0; i < pushV.size(); i++)
		{
			ss.push(pushV[i]);
			while (j < popV.size() && ss.top() == popV[j])
			{
				ss.pop();
				j++;
			}
		}
		return ss.empty();
	}
};
/**
栈的压人弹出序列:
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
*/
void main()
{
	vector<int> pushV = { 1, 2, 3, 4, 5 };
	vector<int> popV = { 4,5, 3, 2, 1 };
	vector<int> popV2 = { 4, 3, 5, 1, 2 };
	Solution s;

	cout << s.IsPopOrder(pushV, popV) << endl;
	cout << s.IsPopOrder(pushV, popV2) << endl;

	system("pause");

	
}