#define _CRT_SECURE_NO_DEPRECATE
#include <set>
#include <iostream>
using namespace std;

int fjzys(int a,int b)
{
	//公倍数等于两数相乘在除以最大公因数
	int k = a;
	for (int i = 1; i <= a;i++)
	{
		if(a%i==0 && b%i==0)
		{
			k = i;
		}
	}
	cout << k <<" "<< (a*b) / k << endl;
	return 0;
}

//http://acm.nyist.net/JudgeOnline/problem.php?pid=40
int main()
{
	int n;
	int a, b;
	cin>>n;
	while (n--)
	{
		cin >> a >> b;
		fjzys(a,b);		
	}
}