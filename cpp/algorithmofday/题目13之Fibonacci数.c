#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include <stdlib.h>

int Fibonacci(int n)
{
	if(n==1 || n==2)
	{
		return 1;
	}
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}
//http://acm.nyist.net/JudgeOnline/problem.php?pid=13
int main()
{
	int count;
	scanf("%d", &count);
	int item;
	while (count--)
	{
		scanf("%d", &item);
		printf("%d\n", Fibonacci(item));
	}
	return 0;
}