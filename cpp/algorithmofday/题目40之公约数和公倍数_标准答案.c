#define _CRT_SECURE_NO_DEPRECATE

#include<stdio.h>
int main()
{
	unsigned int u, v, r, s, i, d;
	scanf("%u", &s);
	for (i = 1; i <= s; i++)
	{
		scanf("%u%u", &u, &v);
		d = u*v;
		while (v != 0)
		{
			r = u%v;
			u = v;
			v = r;
		}
		printf("%u %u\n", u, d / u);
	}
	return 0;
}