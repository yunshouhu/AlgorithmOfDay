#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#define BOOL int
#define TRUE 1
#define FALSE 0

int otherFactorial(int num)
{
	int sum = 1;
	for (int i = 1; i<=num; i++)
	{
		if (i % 2 == 1)
		{
			sum *= i;
		}	
	}
	return sum;	
}
//http://acm.nyist.net/JudgeOnline/problem.php?pid=65
int main()
{
	int n;
	scanf("%d", &n);
	int item;
	while (n--)
	{
		scanf("%d", &item);

		int sum = 0;
		for (int i = 1; i <= item; i++)
		{
			sum += otherFactorial(i);
		}
		printf("%d\n", sum);
	}
}