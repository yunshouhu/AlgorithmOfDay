#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include <limits.h>
#define BOOL int
#define TRUE 1
#define FALSE 0

//��׳�n!=1x2x3x4............N
int factorial(int number)
{
	int sum = 1;
	for (int i = 1; i <= number;i++)
	{
		sum *= i;
	}
	return sum;
}


//int  j = 0;
//int a[10];    //���������
int fjzys(int k,int val)
{
	int i = 2;
	int count = 0;
	while (k >= i)    //�ж�k�Ƿ�ϸ�       
	{
		if (k%i == 0)    //�ж�k�Ƿ�������ǰ����
		{
			//a[j] = i;    //��������
			k /= i;    //����
			i = 2;    //��i���µ���2
			//j++;    //����ֵ
			if(i==val)
			{
				count++;
			}
		}
		else
		{
			i++;    //����������ǰ����Ϊ��������
		}
	}
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
		int total = factorial(a);
		printf("max=%d min=%d %d\n",INT_MAX,INT_MIN, total);
		printf("%d\n", fjzys(total, b));
	}
}