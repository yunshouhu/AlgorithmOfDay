#include <iostream>
using namespace std;//引入命名空间

int g(int m)//原来的多了分号
{
	int s = 1;
	while (m > 0) {

		if (m % 2 == 1)
		{
			//奇数阶乘
			s *= m;
		}	
		m--;
	}
	return s;
}int f(int n)
{
	int sum = 0;//原来的居然使用静态变量
	while (n > 0)
	{
		sum = sum + g(n);
		n--;//原来的进入死循环了

	}
	return sum;
}

//http://acm.nyist.net/JudgeOnline/problem.php?pid=65
int main()
{
	int a;
	cin >> a;
	while (a--) {
		int n;
		cin >> n;
		cout << f(n) << endl;
	}
	return 0;
}