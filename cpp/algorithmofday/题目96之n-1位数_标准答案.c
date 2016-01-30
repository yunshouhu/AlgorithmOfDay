
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>

int main()
{
	int n, m;
	scanf("%d", &n);
	while (n--)
	{
		scanf("\n%*c%d", &m);
		printf("%d\n", m);
	}
	return 0;
}