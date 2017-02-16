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
	可以用位运算实现，
	如果将所有所有数字相异或，则最后的结果肯定是那两个只出现一次的数字异或的结果，

	所以根据异或的结果1所在的最低位，把数字分成两半，每一半里都还有只出现一次的数据和成对出现的数据
	这样继续对每一半相异或则可以分别求出两个只出现一次的数字
	*/
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {

		if (data.size() < 2)
			return;
		int size = data.size();
		int temp = data[0];
		//将所有所有数字相异或，则最后的结果肯定是那两个只出现一次的数字异或的结果，
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

	//异或的方法
	void FindNumsAppearOnce2(vector<int> data, int* num1, int *num2)
	{
		int diff = std::accumulate(data.begin(), data.end(), 0, bit_xor<int>());//累积。连乘 连加
		diff &= -diff;  //即找到最右边1-bit
		*num1 = 0; *num2 = 0;
		for (auto c : data) {
			if ((c&diff) == 0) 
				*num1 ^= c;
			else *num2 ^= c;
		}
	}

	//哈希表法
	void FindNumsAppearOnce3(vector<int> data, int* num1, int *num2)
	{
		unordered_map<int, int> map;
		for (int i = 0; i < data.size(); i++)
			map[data[i]]++;//相当于map.insert(data[i], 1); 当data[i]相同,value=value+1
		vector<int>v;
		for (int i = 0; i < data.size(); i++)
		if (map[data[i]] == 1)
			v.push_back(data[i]);
		*num1 = v[0]; *num2 = v[1];
	}

};

/**
数组中只出现一次的数字:
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
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