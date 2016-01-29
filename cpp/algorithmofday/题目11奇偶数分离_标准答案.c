#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
//http://acm.nyist.net/JudgeOnline/problem.php?pid=11
int main()
{
	int n;
	scanf("%d", &n);
	int a;
	while (n--)
	{
		scanf("%d", &a);
		for (int i = 1; i <= a; i += 2)
			printf("%d ", i);
		puts("");
		for (int i = 2; i <= a; i += 2)
			printf("%d ", i);
		puts("");
	}
}