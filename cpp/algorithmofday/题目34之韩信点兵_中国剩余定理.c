#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#define BOOL int
#define TRUE 1
#define FALSE 0


//http://acm.nyist.net/JudgeOnline/problem.php?pid=34
//���ŵ��֮�й�ʣ�ඨ��: ����3�����֣��ֱ�������������3����5�ͳ���7�����������������
int main()
{
	int a,b,c;
	scanf("%d %d %d", &a,&b,&c);
	int i = 10;
	for (; i <= 100; i++)
	{
		if (i % 3 == a && i % 5 == b && i % 7 == c)
		{
			
			break;
		}
	}
	if (i <=100)
	{
		printf("%d\n", i);

	}
	else {
		printf("No answer\n");
	}

}