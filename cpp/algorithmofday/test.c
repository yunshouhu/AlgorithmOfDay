#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

int main()
{
	int a, b,c;
	while (scanf("%d %d", &a, &b)!=EOF)
	{
		c = a + b;
		printf("%d\n", c);
	}
	
	return 0;
	
}