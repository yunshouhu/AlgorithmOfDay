#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

struct Rectangle
{
	//编号id
	int id;
	int length;
	int with;
};

//注意传递的是引用 否则会在内存中拷贝新值
void doJob(vector<Rectangle> &list);
bool SortByM1(const Rectangle &o1, const Rectangle &o2);

static vector<Rectangle> delList;

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
				rectangle.with = (b);
			}
			else {
				rectangle.length = (b);
				rectangle.with = (a);
			}
			list.push_back(rectangle);
			m--;
		}
		doJob(list);

	
		count--;
	}
}

bool SortByM1(const Rectangle &o1,const Rectangle &o2)
{
	int ret = 0;
	ret = o1.id - o2.id;
	if (ret == 0)
	{
		ret = o1.length - o2.length;
		if (ret==0)
		{
			ret = o1.with - o2.with;
			if (ret == 0)
			{
				delList.push_back(o2);
			}
		}
	}
	if(ret!=0)
	{
		return false;
	}else
	{
		return true;
	}
}

//2.8快速排序
int Partition(vector<Rectangle> &a, int p, int r)
{
	int i = p, j = r + 1;
	Rectangle x = a.at(p);
	while (true)
	{
		//while (a[++i] < x);
		while (SortByM1(a.at(++i), x)==true);
		//while (a[--j] > x);
		while (SortByM1(a.at(--j), x)==false);
		if (i >= j)
			break;
		//Swap(a[i], a[j]);
		Rectangle x = a.at(i);
		a.assign(i, a.at(j));
		a.assign(j, x);

	}
	a[p] = a[j];
	a[j] = x;
	return j;
}


void QuickSort(vector<Rectangle> &a, int p, int r)
{
	if (p < r) {
		int q = Partition(a, p, r);
		QuickSort(a, p, q - 1);
		QuickSort(a, q + 1, r);
	}
}


void doJob(vector<Rectangle> &mylist) {

	vector<Rectangle>::iterator it;
	
	//std::sort(mylist.begin(), mylist.end(), SortByM1);

	QuickSort(mylist, 0, mylist.size());

	for (it = delList.begin(); it != delList.end(); it++)
	{
		mylist.erase(it);

	}
	for (it = mylist.begin(); it != mylist.end(); it++)
	{
		cout << it->id << " " << it->length << " " << it->with << endl;
	
	}
	/**
	unsigned int i = 0;
	for (; i < mylist.size();i++)
	{
		Rectangle rectangle = mylist[i];
		cout << rectangle.id << " " << rectangle.length << " " << rectangle.with << endl;;
	}*/
}
