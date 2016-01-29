#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#define BOOL int
#define TRUE 1
#define FALSE 0

BOOL isPrime(int a)
{
	if (a == 1)
		return FALSE;
	for (int i = 2; i*i<= a; i++)
		if (a%i == 0) 
			return FALSE;
	return TRUE;
}
//http://acm.nyist.net/JudgeOnline/problem.php?pid=22
int main()
{
	int n;
	scanf("%d", &n);
	int a,item,sum;
	while (n--)
	{
		scanf("%d", &a);
		sum = 0;
		for (int i = 0; i < a; i ++)
		{
			scanf("%d", &item);
			if(isPrime(item))
			{
				sum += item;
			}
		}
		printf("%d\n", sum);
	}
}