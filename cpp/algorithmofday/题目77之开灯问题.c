#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#define BOOL int
#define TRUE 1
#define FALSE 0

//http://acm.nyist.net/JudgeOnline/problem.php?pid=77
int main()
{
	int m,n;
	scanf("%d %d",&m, &n);
	int arr[1002] = {0};
	//第一个人把灯全开了
	for (int i = 1; i <= m; i++)
	{
		arr[i] = 1;
	}
	//第2个人按下编号为2的倍数的开关,第3 个人按下编号为3的倍数的开关,第4 个人按下编号为4的倍数的开关...
	for (int i = 1; i <= m; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			int mod = i% j;// 
			if (mod == 0) //
			{
				arr[i] = -arr[i];//取相反数				
			}
		}

	}
	
	for (int i = 1; i <= m; i++)
	{
		if (arr[i] == 1)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	
}