#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

int m, b, c = 0, j = 0;
int a[10];    //���������
int fjzys(int k)
{
	int i = 2;
	while (k >= i)    //�ж�k�Ƿ�ϸ�       
	{
		if (k%i == 0)    //�ж�k�Ƿ�������ǰ����
		{
			a[j] = i;    //��������
			k /= i;    //����
			i = 2;    //��i���µ���2
			j++;    //����ֵ
		}
		else
		{
			i++;    //����������ǰ����Ϊ��������
		}
	}
	return 0;
}
/* ��forʵ������ĺ���
int fjzys(int k)
{
int i=2;
for ( ; i<=k ; i++ )    //������i<=kʱ��ʵ�ָ�ѭ����ÿ��ѭ������i�Լ�1
for ( ; k%i==0 ; j++ )   //��k������ǰ������ʵ�ָ�ѭ����ÿ��ѭ���±�j�Լ�1
{
k/=i;   //ʹk=k/i
a[j]=i;   //��������
}
return 0;
}
�������ĺ������޷�����������ͬ������������90=2*3*3*5��ֻ�����һ��3.
*/

void main()
{
	printf("������һ������\nk=");
	scanf("%d", &m);
	fjzys(m);
	printf("%d=", m);
	for (b = 0; b<(j - 1); b++)    //*����������һ��
	{
		printf("%d", a[b]);
		printf("*");
	}
	printf("%d\n", a[j - 1]);    //������һ��������
}