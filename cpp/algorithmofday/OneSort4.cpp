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
	bool operator==(const Rectangle &s) const {
		return id==s.id && length==s.length && width ==s.width;

	}
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
		while (m > 0)
		{
			int id;
			cin >> id;
			int a;
			cin >> a;
			int b;
			cin >> b;

			Rectangle rectangle;
			rectangle.id = id;
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
	unsigned int i = 0;
	for (; i< delList.size();i++)
	{
		it = std::find(mylist.begin(), mylist.end(), delList[i]);
		//存在问题
		if(it!= mylist.end())
		{
			it=mylist.erase(it);
			//it++;
		}
	}
	for (it = mylist.begin(); it != mylist.end(); it++)	
	{
		cout << it->id << " " << it->length << " " << it->width << endl;
			
	}
}
