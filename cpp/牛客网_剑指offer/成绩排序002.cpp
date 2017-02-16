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
//c/c++֮�ɼ�����std:stable_sort�Խṹ��struct����
/**
���Һ�����
��Ŀ���������⣨�û����ɼ������У����Ի�óɼ��Ӹߵ��ͻ�ӵ͵��ߵ�����,��ͬ�ɼ�
������¼��������ǰ�Ĺ�����
��ʾ��
jack      70
peter     96
Tom       70
smith     67
�Ӹߵ���  �ɼ�
peter     96
jack      70
Tom       70
smith     67
�ӵ͵���
smith     67
Tom       70
jack      70
peter     96

��������:
������У�������Ҫ������˵ĸ�����Ȼ���������򷽷�0�����򣩻���1�������ٷֱ��������ǵ����ֺͳɼ�����һ���ո����
�������:
����ָ����ʽ������ֺͳɼ������ֺͳɼ�֮����һ���ո����

��������:
3
0
fang 90
yang 50
ning 70

�������:
fang 90
ning 70
yang 50
*/
int main()
{
	int count;
	//ѭ����������������
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
		//std::sort(list.begin(), list.end(), my_compare);//��������
		std::stable_sort(list.begin(), list.end(), my_compare);

		for (int i = 0; i < count; i++)
		{
			Student* stu = list.at(i);
			printf("%s %d\n", stu->name, stu->score);

		}
	}
	return 0;
}