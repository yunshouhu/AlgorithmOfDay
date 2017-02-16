#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Student{
	char name[256];
	int score;
	int sore_type;
} Student;

bool my_compare(const Student* stu1, const Student* stu2)
{
	if (stu1->sore_type == 0)
	{
		return stu1->score > stu2->score;
	}
	else
	{
		return stu1->score < stu2->score;
	}
}
//https://www.nowcoder.com/practice/0383714a1bb749499050d2e0610418b1?tpId=40&tqId=21333&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
//成绩排序：std:sort对结构体struct排序。
int main()
{
	int count;
	std::vector<Student*> list;
	//循环处理多个测试用例
	while (cin >> count)
	{

		int type;
		cin >> type;
		list.clear();
		for (int i = 0; i < count; i++)
		{
			char name[256] = { 0 };
			int score;
			cin >> name;
			cin >> score;
			Student* stu = new Student();
			stu->score = score;
			stu->sore_type = type;
			strcpy(stu->name, name);
			list.push_back(stu);
		}
		//std::sort(list.begin(), list.end(), my_compare); //这个失败
		std::stable_sort(list.begin(), list.end(), my_compare);
		for (int i = 0; i < count; i++)
		{
			Student* stu = list.at(i);
			//printf("%s %d\n", stu->name, stu->score);
			cout << stu->name << " " << stu->score << endl;
		}
	}
	return 0;
}