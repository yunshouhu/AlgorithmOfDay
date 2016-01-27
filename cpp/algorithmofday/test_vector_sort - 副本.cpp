// VectorSort.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <algorithm>

//先自定义一个结构体
struct Test {
	int member1;
	int member2;
};

static std::vector<Test> delList;

//自定义排序函数
bool SortByM1(const Test &v1, const Test &v2)//注意：本函数的参数的类型一定要与vector中元素的类型一致
{
	delList.push_back(v1);

	return v1.member1 < v2.member1;//升序排列
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
	插一句，
	vec.begin()对应的位置是向量的第一个位置，
	vec.end()对应的是vector中的最后的一个元素位置的后面的一个位置（我认为，实际上是一个无效位置）
	文档上的定义：Returns an iterator referring to the past-the-end element in the vector container.
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
	//排序之前
	std::cout << "Before Sort:" << std::endl;
	PrintVector(vecTest);

	std::cout << "对向量中的所有元素按member1进行升序排列:" << std::endl;
	std::sort(vecTest.begin(), vecTest.end(), SortByM1);
	PrintVector(vecTest);

	//std::cout<<"对向量中的第2个到第5个元素按member1进行升序排列:"<<std::endl;
	//std::sort(vecTest.begin()+1,vecTest.begin()+5,SortByM1);//vecTest.begin()+5为第6个位置
	//PrintVector(vecTest);
	std::cout << "对delList排列:" << std::endl;
	PrintVector(delList);

	return 0;
}
