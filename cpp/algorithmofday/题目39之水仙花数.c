#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include <string.h>
#define BOOL int
#define TRUE 1
#define FALSE 0

BOOL isShuiXianHua(int number)
{
	if (number == 1)
		return TRUE;
	static char buffer[1024];
	sprintf(buffer, "%d", number);
	unsigned int len = strlen(buffer);
	int sum = 0;
	for (int i = 0; i < len;i++)
	{
		int data = buffer[i] - '0';
		data = data*data*data;
		sum += data;
	}
	if(sum==number)
	{
		return TRUE;
	}else
	{
		return FALSE;
	}
}
//http://acm.nyist.net/JudgeOnline/problem.php?pid=39
int main()
{
	int a;
	scanf("%d", &a);
	while (a!=0)
	{
		if(isShuiXianHua(a))
		{
			printf("Yes\n");
		}else
		{
			printf("No\n");
		}
		scanf("%d", &a);	
	}
}