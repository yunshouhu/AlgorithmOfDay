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
	//唯一标识符
	int no;
};

//注意传递的是引用 否则会在内存中拷贝新值
void doJob(vector<Rectangle> &list);
int SortByM1(const Rectangle &o1, const Rectangle &o2);
vector<Rectangle> delList;


 //http://acm.nyist.net/JudgeOnline/problem.php?pid=8
//提交后Accepted
int main()
{

	int count;
	int m;
	cin >> count;
	while (count > 0) {
		cin >> m;//m个长方形

		vector<Rectangle> list;
		int no = 0;
		while (m > 0)
		{
			int id;
			cin >> id;
			int a;
			cin >> a;
			int b;
			cin >> b;

			Rectangle rectangle;
			no++;
			rectangle.no = no;
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

int SortByM1(const Rectangle &o1,const Rectangle &o2)
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
		for (j = 0; j<i; ++j)
		{
			if(SortByM1(myList.at(j),myList.at(j+1))>0)
			{
				t = myList.at(j);
				myList[j]=myList.at(j + 1);
				myList[j + 1]= t;
				change = true;
			}
		}
			
	}
}


void doJob(vector<Rectangle> &mylist) {

	vector<Rectangle>::iterator it;
	
	//std::sort(mylist.begin(), mylist.end(), SortByM1); //存在问题

	bubble_sort(mylist, mylist.size());//只能自己定义冒泡排序

	vector<Rectangle>::iterator itor2;
	for (it = mylist.begin(); it != mylist.end();)
	{
		itor2 = it;
		//判断是否删除
		vector<Rectangle>::iterator it_del;
		bool isDel = false;
		for (it_del = delList.begin(); it_del != delList.end();)
		{
			if(it_del->no == it->no)
			{
				isDel = true;
				break;
			}
			it_del++;
		}
		if(isDel==true)
		{
			it = mylist.erase(itor2);//erase这个api 存在太多问题了
		}
		if(it!= mylist.end())
		{
			++it;
		}
		
	}

	for (it = mylist.begin(); it != mylist.end(); it++)
	{
		cout << it->id << " " << it->length << " " << it->with << endl;
	
	}
}
