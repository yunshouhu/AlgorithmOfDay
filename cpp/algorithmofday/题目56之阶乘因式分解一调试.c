#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include <limits.h>
#define BOOL int
#define TRUE 1
#define FALSE 0

//求阶乘n!=1*2*3*...*n
int factorial_fjzys(int number, int val)
{

	static char buffer[1024];
	int buffer_i = 0;
	int count = 0;

	for (int j = 0; j < number;j++)
	{
		int k = j + 1;

		int i = 2;		
		while (k >= i)    //判断k是否合格       
		{
			if (k%i == 0)    //判断k是否整除当前因数
			{
				buffer[buffer_i] = i+'0';    //存入因数
				if (i == val)
				{
					count++;
				}
				k /= i;    //余数
				i = 2;    //令i重新等于2
				buffer_i++;
				
			}
			else
			{
				i++;    //不能整除则当前因数为非质因数
			}
		}
	}
	/**
	for (int j = 0; j < buffer_i; j++)
	{
		printf("%c*", buffer[j]);
	}
	printf("\n");*/
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
		int total = factorial_fjzys(a,b);
		//printf("max=%d min=%d %d\n",INT_MAX,INT_MIN, total);
		printf("%d\n",total);
	}
}