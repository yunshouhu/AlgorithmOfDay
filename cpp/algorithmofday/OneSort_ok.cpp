#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

struct Rectangle
{
	int id;
	int length;
	int width;
	int number;
};

void doJob(vector<Rectangle> &list);
int SortByM1(const Rectangle &o1, const Rectangle &o2);
vector<Rectangle> delList;
 //http://acm.nyist.net/JudgeOnline/problem.php?pid=8
int main()
{
	int count;
	int m;
	cin >> count;
	while (count > 0) {
		cin >> m;//m个长方形
		vector<Rectangle> list;
		int number = 0;
		while (m > 0)
		{
			int id;
			cin >> id;
			int a;
			cin >> a;
			int b;
			cin >> b;

			Rectangle rectangle;
			number++;
			rectangle.id = id;
			rectangle.number = number;
			if (a > b)
			{
				rectangle.length = (a);
				rectangle.width = (b);
			}
			else {
				rectangle.length = (b);
				rectangle.width = (a);
			}
			list.push_back(rectangle);
			m--;
		}
		doJob(list);	
		count--;
	}
}
int SortByM1(const Rectangle &o1, const Rectangle &o2)
{
	int ret = 0;
	ret = o1.id - o2.id;
	if (ret == 0)
	{
		ret = o1.length - o2.length;
		if (ret == 0)
		{
			ret = o1.width - o2.width;
			if (ret == 0)
			{
				delList.push_back(o2);
			}
		}
	}
	return ret;
}
void bubble_sort(vector<Rectangle> &myList, int n)
{
	int i, j;
	Rectangle t;
	bool change;
	for (i = n - 1, change = true; i > 1 && change; --i)
	{
		change = false;
		for (j = 0; j < i; ++j)
		{
			if (SortByM1(myList.at(j), myList.at(j + 1))>0)
			{
				t = myList.at(j);
				myList[j] = myList.at(j + 1);
				myList[j + 1] = t;
				change = true;
			}
		}

	}
}


void doJob(vector<Rectangle> &mylist) {
	vector<Rectangle>::iterator it;

	bubble_sort(mylist, mylist.size());
	vector<Rectangle>::iterator itor2;
	for (it = mylist.begin(); it != mylist.end();)
	{
		itor2 = it;
		//判断是否删除
		vector<Rectangle>::iterator it_del;
		bool isDel = false;
		for (it_del = delList.begin(); it_del != delList.end();)
		{
			if (it_del->number == it->number)
			{
				isDel = true;
				break;
			}
			it_del++;
		}
		if (isDel == true)
		{
			it = mylist.erase(itor2);//erase这个api 存在太多问题了
		}
		if (it != mylist.end())
		{
			++it;
		}

	}

	for (it = mylist.begin(); it != mylist.end(); it++)
	{
		cout << it->id << " " << it->length << " " << it->width << endl;

	}
}
