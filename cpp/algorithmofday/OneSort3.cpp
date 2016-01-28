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
	//std::remove
	bool operator==(const Rectangle &s) const {
		//return score <= s.score; //这段代码会出现内存越界，应该算是stl sort一个容易踩到的坑
		return id==s.id && length==s.length && with==s.with;

	}
};

void doJob(vector<Rectangle> &list);
int SortByM1(const Rectangle &o1, const Rectangle &o2);
vector<Rectangle> delList;

 //http://acm.nyist.net/JudgeOnline/problem.php?pid=8
//提交后不对
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
//stl的坑逼  不能使用=返回 只能使用> <
int SortByM1(const Rectangle &o1,const Rectangle &o2)
{
	int ret = -1;
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
				//cout << "push_back="<<o2.id << " " << o2.length << " " <<o2.with << endl;
				return o1.with > o2.with;
			}else {

				return o1.with < o2.with;
			}
		}else {

			return o1.length < o2.length;
		}
	}else {

		return o1.id < o2.id;
	}
}



void doJob(vector<Rectangle> &mylist) {
	vector<Rectangle>::iterator it;
	std::sort(mylist.begin(), mylist.end(), SortByM1); //存在问题
	unsigned int i = 0;
	if(delList.size()>0)
	{
		i = 1;
	}
	for (; i< delList.size();i++)
	{
		it = std::find(mylist.begin(), mylist.end(), delList.at(i));
		if(it!= mylist.end())
		{
			mylist.erase(it);
			/**
			//但这个函数只是把val移到vec的末尾，并不真正删除 真正删除还是要调用一次erase函数
			it = std::remove(mylist.begin(), mylist.end(), delList.at(i));
			mylist.pop_back();
			*/
		}

		
		
	}

	for (it = mylist.begin(); it != mylist.end(); it++)
	{
		cout << it->id << " " << it->length << " " << it->with << endl;
	
	}
}
