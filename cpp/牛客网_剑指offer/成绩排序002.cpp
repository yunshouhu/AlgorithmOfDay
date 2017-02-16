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
//c/c++之成绩排序：std:stable_sort对结构体struct排序。
/**
查找和排序
题目：输入任意（用户，成绩）序列，可以获得成绩从高到低或从低到高的排列,相同成绩
都按先录入排列在前的规则处理。
例示：
jack      70
peter     96
Tom       70
smith     67
从高到低  成绩
peter     96
jack      70
Tom       70
smith     67
从低到高
smith     67
Tom       70
jack      70
peter     96

输入描述:
输入多行，先输入要排序的人的个数，然后输入排序方法0（降序）或者1（升序）再分别输入他们的名字和成绩，以一个空格隔开
输出描述:
按照指定方式输出名字和成绩，名字和成绩之间以一个空格隔开

输入例子:
3
0
fang 90
yang 50
ning 70

输出例子:
fang 90
ning 70
yang 50
*/
int main()
{
	int count;
	//循环处理多个测试用例
	while (scanf("%d", &count) != EOF)
	{

		int type;
		scanf("%d", &type);
		std::vector<Student*> list;
		for (int i = 0; i < count; i++)
		{
			char name[256] = { 0 };
			int score;
			scanf("%s", name);
			scanf("%d", &score);
			Student* stu = new Student();
			stu->score = score;
			stu->sore_type = type;
			strcpy(stu->name, name);
			list.push_back(stu);
		}
		//std::sort(list.begin(), list.end(), my_compare);//存在问题
		std::stable_sort(list.begin(), list.end(), my_compare);

		for (int i = 0; i < count; i++)
		{
			Student* stu = list.at(i);
			printf("%s %d\n", stu->name, stu->score);

		}
	}
	return 0;
}