#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include <math.h>
//http://acm.nyist.net/JudgeOnline/problem.php?pid=22
int main()
{
	int m, n, i, j, a[1000], flag = 0;
	long s;
	scanf("%d", &m);
	while (m--)
	{
		s = 0;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (i = 0; i < n; i++)
		{
			if (a[i] == 1)	continue;
			flag = 0;
			for (j = 2; j <= sqrt(a[i]); j++)
			{
				if (a[i] % j == 0)
				{
					flag = 1; break;
				}
			}
			if (flag == 0)	s += a[i];
		}
		printf("%d\n", s);
	}
	return 0;
}