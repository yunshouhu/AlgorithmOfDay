#define _CRT_SECURE_NO_DEPRECATE

#include<stdio.h>
int main() {
	int n, k, m;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		m = 0;
		for (int j = 1; j <= k; j++)
			if (i % j == 0) 
				m++;
		if (m % 2 == 1)
			printf("%d ", i);
	}
}
