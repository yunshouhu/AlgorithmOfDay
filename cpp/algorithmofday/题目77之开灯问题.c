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
	//��һ���˰ѵ�ȫ����
	for (int i = 1; i <= m; i++)
	{
		arr[i] = 1;
	}
	//��2���˰��±��Ϊ2�ı����Ŀ���,��3 ���˰��±��Ϊ3�ı����Ŀ���,��4 ���˰��±��Ϊ4�ı����Ŀ���...
	for (int i = 1; i <= m; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			int mod = i% j;// 
			if (mod == 0) //
			{
				arr[i] = -arr[i];//ȡ�෴��				
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