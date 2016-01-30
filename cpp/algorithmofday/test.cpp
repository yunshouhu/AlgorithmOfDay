#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<math.h>
int sushu(int n);
int main()
{
	int n, m, i;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &m);
		if (sushu(m) == 1)
		{
			printf("%d 0\n", m); continue;
		}

		else
		{
			for (i = 1; m - i > -1; i++)
			{
				if (sushu(m - i) == 1)
				{
					printf("%d %d\n", m - i, i); break;
				}
				if (sushu(m + i) == 1)
				{
					printf("%d %d\n", m + i, i); break;
				}
			}
		}
	}

	return 0;
}
int sushu(int n)
{
	int leap = 1;
	int i, m, t;
	t = sqrt(n);
	if (n == 2)
		leap = 1;
	else if (n > 2)
	{
		for (i = 2; i <= t; i++)
		{
			if (n%i == 0)
			{
				leap = 0;
				break;
			}
		}
	}
	else
		leap = 0;
	return leap;
}