#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define BOOL int
#define TRUE 1
#define FALSE 0
//http://acm.nyist.net/JudgeOnline/problem.php?pid=64
int main()
{
	int count;
	scanf("%d", &count);
	int n,m;
	while (count--)
	{
		scanf("%d %d", &n,&m);
		int x = 2 * n - m / 2;
		int y = m / 2 - n;
		if(x>=0 && y>=0 && m %2==0)
		{
			printf("%d %d\n", x, y);
		}else
		{
			printf("No answer\n");
		}
		
	}
}