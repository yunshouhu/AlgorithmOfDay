#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include <limits.h>
#define BOOL int
#define TRUE 1
#define FALSE 0

//��׳�n!=1*2*3*...*n
int factorial_fjzys(int number, int val)
{

	static char buffer[1024];
	int buffer_i = 0;
	int count = 0;

	for (int j = 0; j < number;j++)
	{
		int k = j + 1;

		int i = 2;		
		while (k >= i)    //�ж�k�Ƿ�ϸ�       
		{
			if (k%i == 0)    //�ж�k�Ƿ�������ǰ����
			{
				buffer[buffer_i] = i+'0';    //��������
				if (i == val)
				{
					count++;
				}
				k /= i;    //����
				i = 2;    //��i���µ���2
				buffer_i++;
				
			}
			else
			{
				i++;    //����������ǰ����Ϊ��������
			}
		}
	}
	/**
	for (int j = 0; j < buffer_i; j++)
	{
		printf("%c*", buffer[j]);
	}
	printf("\n");*/
	return count;
}



//http://acm.nyist.net/JudgeOnline/problem.php?pid=56
int main()
{
	int n;
	scanf("%d", &n);
	int a,b;
	while (n--)
	{
		scanf("%d %d", &a,&b);	
		//16 2 20922789888000 >2147483647
		int total = factorial_fjzys(a,b);
		//printf("max=%d min=%d %d\n",INT_MAX,INT_MIN, total);
		printf("%d\n",total);
	}
}