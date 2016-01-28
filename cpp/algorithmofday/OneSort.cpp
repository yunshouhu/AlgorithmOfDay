#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

struct Rectangle
{
	//���id
	int id;
	int length;
	int with;
	//Ψһ��ʶ��
	int no;
};

//ע�⴫�ݵ������� ��������ڴ��п�����ֵ
void doJob(vector<Rectangle> &list);
int SortByM1(const Rectangle &o1, const Rectangle &o2);
vector<Rectangle> delList;


 //http://acm.nyist.net/JudgeOnline/problem.php?pid=8
//�ύ��Accepted
int main()
{

	int count;
	int m;
	cin >> count;
	while (count > 0) {
		cin >> m;//m��������

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
	
	//std::sort(mylist.begin(), mylist.end(), SortByM1); //��������

	bubble_sort(mylist, mylist.size());//ֻ���Լ�����ð������

	vector<Rectangle>::iterator itor2;
	for (it = mylist.begin(); it != mylist.end();)
	{
		itor2 = it;
		//�ж��Ƿ�ɾ��
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
			it = mylist.erase(itor2);//erase���api ����̫��������
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
