#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#define BOOL int
#define TRUE 1
#define FALSE 0

int factorial_fjzys(int number, int val)
{
	int count = 0;
	for (int j = 0; j < number;j++)
	{
		int k = j + 1;
		//对阶乘里面的每一个k做质因数分解
		int i = 2;		
		while (k >= i)   
		{
			if (k%i == 0)   
			{
				if (i == val)
				{
					count++;
				}
				k /= i;   
				i = 2;  
			}else
			{
				i++;    
			}
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
		int total = factorial_fjzys(a,b);
		printf("%d\n",total);
	}
}