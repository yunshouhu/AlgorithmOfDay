#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

void getLenForYueshu(int data)
{
	int count = 1;
	for (int i = 1; i <= data / 2; i++)
	{
		if (data % i == 0)
		{
			count++;
		}
	}
	printf("%d\n", count);
}
//��Ҫ�����ж�һ���� i �м���Լ��ʱ��1ѭ����sqrt(i)���ɣ���Ȼ����ʱ��ᳬ��Ҫ��
void sum_prime(int n)
{
	int sum = 0;
	double tmp = sqrt(n);
	for (int i = 1; i <= tmp; i++){
		if (n % i == 0){
			if (i == tmp){
				sum += 1;
			}
			else{
				sum += 2;
			}
		}
	}
	printf("%d\n", sum);
}

int numOfDivisor(int num)
{
	int ans = 0;
	int i;
	for (i = 1; i*i<num; i++)
	{
		if (num%i == 0)
			ans += 2;
	}
	if (i*i == num) ans++;

	printf("%d\n", ans);
	return ans;
}
//https://www.nowcoder.com/practice/04c8a5ea209d41798d23b59f053fa4d6?tpId=40&tqId=21334&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
/**
Լ���ĸ�����
����n������,�������ÿ������Լ���ĸ���
��������:
����ĵ�һ��ΪN��������ĸ���(N<=1000)
��������1�а���N������������ÿ�����ķ�ΧΪ(1<=Num<=1000000000)
��N=0ʱ���������

�������:
�����ж����������ݣ�����ÿ���������ݣ�
���N�У�����ÿһ�ж�Ӧ�����һ������Լ���ĸ�����

��������:
5
1 3 4 6 12
�������:
1
2
3
4
6
*/
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			int data;
			scanf("%d", &data);
			//getLenForYueshu(data);
			//sum_prime(data);
			numOfDivisor(data);

		}
	}

	return 0;
}