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
	ģ���ջ��������ԭ��������ѹջ��ջ��Ԫ����������ջ������ȣ������ͬ���ջ��
	�����ͬ�����ѹջ��ֱ��ԭ��������������ѹջ��ϡ�
	���ջ���Ƿ�Ϊ�գ����գ�˵����ջ���п���ԭ���н���ջ�����õ�������˵����ջ���в�����ԭ���н���ջ�����õ���
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
ջ��ѹ�˵�������:
���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ�
��������1,2,3,4,5��ĳջ��ѹ��˳������4��5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
��4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�
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