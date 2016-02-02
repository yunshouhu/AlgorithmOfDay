#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include <limits.h>
#define BOOL int
#define TRUE 1
#define FALSE 0

//求阶乘n!=1x2x3x4............N
int factorial(int number)
{
	int sum = 1;
	for (int i = 1; i <= number;i++)
	{
		sum *= i;
	}
	return sum;
}


//int  j = 0;
//int a[10];    //存放质因数
int fjzys(int k,int val)
{
	int i = 2;
	int count = 0;
	while (k >= i)    //判断k是否合格       
	{
		if (k%i == 0)    //判断k是否整除当前因数
		{
			//a[j] = i;    //存入因数
			k /= i;    //余数
			i = 2;    //令i重新等于2
			//j++;    //计数值
			if(i==val)
			{
				count++;
			}
		}
		else
		{
			i++;    //不能整除则当前因数为非质因数
		}
	}
	return count;
}


//http://acm.nyist.net/JudgeOnline/problem.php?pid=56
int main()
{
	int n;
	scanf("%d", &n);
	int a,b;
	while (n--)
	{
		scanf("%d %d", &a,&b);	
		//16 2 20922789888000 >2147483647
		int total = factorial(a);
		printf("max=%d min=%d %d\n",INT_MAX,INT_MIN, total);
		printf("%d\n", fjzys(total, b));
	}
}