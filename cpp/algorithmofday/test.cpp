#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

int m, b, c = 0, j = 0;
int a[10];    //存放质因数
int fjzys(int k)
{
	int i = 2;
	while (k >= i)    //判断k是否合格       
	{
		if (k%i == 0)    //判断k是否整除当前因数
		{
			a[j] = i;    //存入因数
			k /= i;    //余数
			i = 2;    //令i重新等于2
			j++;    //计数值
		}
		else
		{
			i++;    //不能整除则当前因数为非质因数
		}
	}
	return 0;
}
/* 用for实现上面的函数
int fjzys(int k)
{
int i=2;
for ( ; i<=k ; i++ )    //当因数i<=k时，实现该循环，每次循环因数i自加1
for ( ; k%i==0 ; j++ )   //当k整除当前因数，实现该循环，每次循环下标j自加1
{
k/=i;   //使k=k/i
a[j]=i;   //存入因数
}
return 0;
}
解决上面的函数，无法输出，多个相同的质因数，如90=2*3*3*5，只能输出一个3.
*/

void main()
{
	printf("请输入一个整数\nk=");
	scanf("%d", &m);
	fjzys(m);
	printf("%d=", m);
	for (b = 0; b<(j - 1); b++)    //*比质因数少一个
	{
		printf("%d", a[b]);
		printf("*");
	}
	printf("%d\n", a[j - 1]);    //输出最后一个质因数
}