#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#define BOOL int
#define TRUE 1
#define FALSE 0

//http://acm.nyist.net/JudgeOnline/problem.php?pid=74
int main()
{
	int m,n;
	scanf("%d %d", &m,&n);
	while (m!=0 && n!=0)
	{
		//int sum = m + n;
		char a[128], b[128];
		sprintf(a, "%d", m);
		sprintf(b, "%d", n);
		BOOL jinwei=FALSE;
		int jinwei_count = 0;
		for (int i = 2; i >= 0;i--)
		{
			int a_int = a[i] - '0';
			int b_int = b[i] - '0';
			int tmp = a_int+b_int;
			if (jinwei == TRUE)
			{
				tmp = tmp + 1;
			}
			if (tmp >= 10)
			{
				jinwei = TRUE;
				jinwei_count++;
			}else {
				jinwei = FALSE;
			}
		}
		printf("%d\n", jinwei_count);
		scanf("%d %d", &m, &n);
	}
}