#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
void main()
{
	int m, n, i, s1, s2; 
	scanf("%d", &m); 
	while (m--)
	{
		scanf("%d", &n);
		for (i = 3, s1 = s2 = 1; i <= n; i++)
		{
			s1 = s1 + s2; 
			s2 = s1 - s2;
		}
		printf("%d\n", s1);
	}
}