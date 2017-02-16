#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <functional>
using namespace std;

class Solution {
public:
	//ʹ�ü򵥴ֱ���ȫ������ķ���������ȡ�úܺõ����ܣ���ΪֻҪ��k����������ʹ����С�ѾͿ����ˡ�
	//(�����Ҫȡ���ֵ���������ѣ�
	void heapSort(vector<int> &input, int root, int end)
	{
		for (int j = end - 1; j >= root; j--)
		{
			int parent = (j + root - 1) / 2;
			if (input[parent]>input[j])
			{
				int temp = input[j];
				input[j] = input[parent];
				input[parent] = temp;
			}
		}
	}
	//��׼������������
	vector<int> GetLeastNumbers_Solution_headSort_custom(vector<int> input, int k) {
		vector<int> result;
		if (k>input.size())
			return result;

		for (int i = 0; i<k; i++)
		{
			heapSort(input, i, input.size());
			result.push_back(input[i]);
		}
		return result;
	}
	//��������ȫ����
	vector<int> GetLeastNumbers_Solution_allsort(vector<int> input, int k) {
		vector<int> res;
		if (input.empty() || k>input.size()) return res;

		sort(input.begin(), input.end());

		for (int i = 0; i<k; i++)
			res.push_back(input[i]);

		return res;
	}
	int Partition(vector<int>& input, int begin, int end)
	{
		int low = begin;
		int high = end;

		int pivot = input[low];
		while (low<high)
		{
			while (low<high&&pivot <= input[high])
				high--;
			input[low] = input[high];
			while (low<high&&pivot >= input[low])
				low++;
			input[high] = input[low];
		}
		input[low] = pivot;
		return low;
	}
	//��������Partiton˼��
	vector<int> GetLeastNumbers_Solution_Partiton(vector<int> input, int k) {

		int len = input.size();
		if (len == 0 || k>len || k <= 0) return vector<int>();
		if (len == k) return input;

		int start = 0;
		int end = len - 1;
		int index = Partition(input, start, end);
		while (index != (k - 1))
		{
			if (index>k - 1)
			{
				end = index - 1;
				index = Partition(input, start, end);
			}
			else
			{
				start = index + 1;
				index = Partition(input, start, end);
			}
		}

		vector<int> res(input.begin(), input.begin() + k);

		return res;
	}
	//������
	vector<int> GetLeastNumbers_Solution_heapSort(vector<int> input, int k) {
		int len = input.size();
		if (len <= 0 || k>len || k <= 0) return vector<int>();

		vector<int> res(input.begin(), input.begin() + k);
		//����
		make_heap(res.begin(), res.end());

		for (int i = k; i<len; i++)
		{
			if (input[i]<res[0])
			{
				//��pop,Ȼ����������ɾ��
				pop_heap(res.begin(), res.end());
				res.pop_back();
				//���������м��룬��push
				res.push_back(input[i]);
				push_heap(res.begin(), res.end());
			}
		}
		//ʹ���С�������
		sort_heap(res.begin(), res.end());

		return res;

	}
	//�������multiset����  ���÷º����ı�����˳�� ʱ�临�Ӷ�O��nlogk�� 
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		int len = input.size();
		if (len <= 0 || k>len || k <= 0) return vector<int>();

		//�º����е�greater<T>ģ�壬�Ӵ�С����
		multiset<int, greater<int> > leastNums;
		vector<int>::iterator vec_it = input.begin();
		for (; vec_it != input.end(); vec_it++)
		{
			//��ǰk��Ԫ�ز��뼯��
			if (leastNums.size()<k)
				leastNums.insert(*vec_it);
			else
			{
				//��һ��Ԫ�������ֵ
				multiset<int, greater<int> >::iterator greatest_it = leastNums.begin();
				//�������Ԫ��<��һ��Ԫ�أ�ɾ����һ�������뵱ǰԪ��
				if (*vec_it<*(leastNums.begin()))
				{
					leastNums.erase(greatest_it);
					leastNums.insert(*vec_it);
				}
			}
		}

		return std::vector<int>(leastNums.begin(), leastNums.end());
	}
};
void show(vector<int> list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << list.at(i) << " ";
	}
	cout << endl;
}
/**
�㷨֮ÿ��һ�⣺��С��K����
����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��
https://www.nowcoder.com/questionTerminal/6a296eb82cf844ca8539b57c23e6e9bf
*/
void main()
{
	vector<int> list = { 4, 5, 1, 6, 2, 7, 3, 8 };
	show(list);
	Solution s;
	vector<int> result=s.GetLeastNumbers_Solution(list, 4);
	show(result);

	show(list);
	result = s.GetLeastNumbers_Solution_Partiton(list, 4);
	show(result);

	show(list);
	result = s.GetLeastNumbers_Solution_allsort(list, 4);
	show(result); 

	show(list);
	result = s.GetLeastNumbers_Solution_headSort_custom(list, 4);
	show(result);

	show(list);
	result = s.GetLeastNumbers_Solution_heapSort(list, 4);
	show(result);
	system("pause");

}