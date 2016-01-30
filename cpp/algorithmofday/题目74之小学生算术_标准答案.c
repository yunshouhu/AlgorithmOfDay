#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

int main()
{
	int a, b, c, d, e, f, n, m, i;
	for (;;)
	{
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0)
			return 0;
		else
		{
			i = 0;
			a = n / 100; b = n % 100 / 10; c = n % 10;
			d = m / 100; e = m % 100 / 10; f = m % 10;
			if (c + f >= 10)
			{
				i += 1; b += 1;
			}
			if (b + e >= 10)
			{
				i += 1; a += 1;
			}
			if (a + d >= 10)
			{
				i += 1;
			}
			printf("%d\n", i);
		}
	}
	return 0;
}
