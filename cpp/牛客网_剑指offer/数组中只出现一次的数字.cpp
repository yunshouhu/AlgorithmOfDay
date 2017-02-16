#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <functional>
#include <unordered_map>
#include <numeric>
using namespace std;

class Solution {
public:
	/**
	������λ����ʵ�֣�
	���������������������������Ľ���϶���������ֻ����һ�ε��������Ľ����

	���Ը������Ľ��1���ڵ����λ�������ֳַ����룬ÿһ���ﶼ����ֻ����һ�ε����ݺͳɶԳ��ֵ�����
	����������ÿһ�����������Էֱ��������ֻ����һ�ε�����
	*/
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {

		if (data.size() < 2)
			return;
		int size = data.size();
		int temp = data[0];
		//������������������������Ľ���϶���������ֻ����һ�ε��������Ľ����
		for (int i = 1; i < size; i++)
			temp = temp^data[i];
		if (temp == 0)
			return;
		int index = 0;
		while ((temp & 1) == 0)
		{
			temp = temp >> 1;
			++index;
		}
		*num1 = *num2 = 0;
		for (int i = 0; i < size; i++)
		{
			if (IsBit(data[i], index))
				*num1 ^= data[i];
			else
				*num2 ^= data[i];
		}

	}
	bool IsBit(int num, int index)
	{
		num = num >> index;
		return (num & 1);

	}

	//���ķ���
	void FindNumsAppearOnce2(vector<int> data, int* num1, int *num2)
	{
		int diff = std::accumulate(data.begin(), data.end(), 0, bit_xor<int>());//�ۻ������� ����
		diff &= -diff;  //���ҵ����ұ�1-bit
		*num1 = 0; *num2 = 0;
		for (auto c : data) {
			if ((c&diff) == 0) 
				*num1 ^= c;
			else *num2 ^= c;
		}
	}

	//��ϣ��
	void FindNumsAppearOnce3(vector<int> data, int* num1, int *num2)
	{
		unordered_map<int, int> map;
		for (int i = 0; i < data.size(); i++)
			map[data[i]]++;//�൱��map.insert(data[i], 1); ��data[i]��ͬ,value=value+1
		vector<int>v;
		for (int i = 0; i < data.size(); i++)
		if (map[data[i]] == 1)
			v.push_back(data[i]);
		*num1 = v[0]; *num2 = v[1];
	}

};

/**
������ֻ����һ�ε�����:
һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�
https://www.nowcoder.com/questionTerminal/e02fdb54d7524710a7d664d082bb7811
*/
void main()
{
	vector<int> list = {2, 4, 3, 6, 3, 2, 5, 5};
	int data1;
	int data2;
	Solution ss;
	ss.FindNumsAppearOnce(list, &data1, &data2);
	cout << data1 <<","<<data2<< endl;

	ss.FindNumsAppearOnce2(list, &data1, &data2);
	cout << data1 << "," << data2 << endl;

	ss.FindNumsAppearOnce3(list, &data1, &data2);
	cout << data1 << "," << data2 << endl;
	system("pause");

}