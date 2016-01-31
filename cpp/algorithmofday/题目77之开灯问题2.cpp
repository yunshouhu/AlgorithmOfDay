#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<math.h>
int main()
{
	int n, k, i, j;
	scanf("%d %d", &n, &k);
	int c[1000] = { 0 };
	for (i = 0; i < n; i++)
	{
		c[i] = 1;
	}
	for (i = 2; i <= k; i++)
	{
		for (j = 1; j*i <= n; j++)
		{
			c[j*i - 1] = -c[j*i - 1];
		}
	}
	for (i = 0; i < n; i++)
	{
		if (c[i] == 1)
			printf("%d ", i + 1);
	}
	return 0;
}