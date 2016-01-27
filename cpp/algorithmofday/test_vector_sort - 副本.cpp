// VectorSort.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <algorithm>

//���Զ���һ���ṹ��
struct Test {
	int member1;
	int member2;
};

static std::vector<Test> delList;

//�Զ���������
bool SortByM1(const Test &v1, const Test &v2)//ע�⣺�������Ĳ���������һ��Ҫ��vector��Ԫ�ص�����һ��
{
	delList.push_back(v1);

	return v1.member1 < v2.member1;//��������
}

void MyPushback(std::vector<Test> & vecTest, const int &m1, const int &m2)
{
	Test test;
	test.member1 = m1;
	test.member2 = m2;
	vecTest.push_back(test);
}

void PrintVector(std::vector<Test> & vec)
{
	/*
	��һ�䣬
	vec.begin()��Ӧ��λ���������ĵ�һ��λ�ã�
	vec.end()��Ӧ����vector�е�����һ��Ԫ��λ�õĺ����һ��λ�ã�����Ϊ��ʵ������һ����Чλ�ã�
	�ĵ��ϵĶ��壺Returns an iterator referring to the past-the-end element in the vector container.
	*/
	for (std::vector<Test>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << it->member1 << '=' << it->member2 <<" ";
	}
	std::cout<<std::endl;
}

int main(int argc, char* argv[])
{
	std::vector<Test> vecTest;
	MyPushback(vecTest, 9, 1);
	MyPushback(vecTest, 8, 2);
	MyPushback(vecTest, 7, 3);
	MyPushback(vecTest, 6, 4);
	MyPushback(vecTest, 5, 5);
	MyPushback(vecTest, 4, 6);
	MyPushback(vecTest, 3, 7);
	MyPushback(vecTest, 2, 8);
	MyPushback(vecTest, 1, 9);
	//����֮ǰ
	std::cout << "Before Sort:" << std::endl;
	PrintVector(vecTest);

	std::cout << "�������е�����Ԫ�ذ�member1������������:" << std::endl;
	std::sort(vecTest.begin(), vecTest.end(), SortByM1);
	PrintVector(vecTest);

	//std::cout<<"�������еĵ�2������5��Ԫ�ذ�member1������������:"<<std::endl;
	//std::sort(vecTest.begin()+1,vecTest.begin()+5,SortByM1);//vecTest.begin()+5Ϊ��6��λ��
	//PrintVector(vecTest);
	std::cout << "��delList����:" << std::endl;
	PrintVector(delList);

	return 0;
}
