#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <functional>
using namespace std;

class Solution {
public:
	//使用简单粗暴的全部排序的方法并不能取得很好的性能，因为只要求k个数，所以使用最小堆就可以了。
	//(如果是要取最大值就是用最大堆）
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
	//标准方法：堆排序
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
	//方法二：全排序
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
	//方法三：Partiton思想
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
	//堆排序
	vector<int> GetLeastNumbers_Solution_heapSort(vector<int> input, int k) {
		int len = input.size();
		if (len <= 0 || k>len || k <= 0) return vector<int>();

		vector<int> res(input.begin(), input.begin() + k);
		//建堆
		make_heap(res.begin(), res.end());

		for (int i = k; i<len; i++)
		{
			if (input[i]<res[0])
			{
				//先pop,然后在容器中删除
				pop_heap(res.begin(), res.end());
				res.pop_back();
				//先在容器中加入，再push
				res.push_back(input[i]);
				push_heap(res.begin(), res.end());
			}
		}
		//使其从小到大输出
		sort_heap(res.begin(), res.end());

		return res;

	}
	//红黑树：multiset集合  利用仿函数改变排序顺序 时间复杂度O（nlogk） 
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		int len = input.size();
		if (len <= 0 || k>len || k <= 0) return vector<int>();

		//仿函数中的greater<T>模板，从大到小排序
		multiset<int, greater<int> > leastNums;
		vector<int>::iterator vec_it = input.begin();
		for (; vec_it != input.end(); vec_it++)
		{
			//将前k个元素插入集合
			if (leastNums.size()<k)
				leastNums.insert(*vec_it);
			else
			{
				//第一个元素是最大值
				multiset<int, greater<int> >::iterator greatest_it = leastNums.begin();
				//如果后续元素<第一个元素，删除第一个，加入当前元素
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
算法之每日一题：最小的K个数
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
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