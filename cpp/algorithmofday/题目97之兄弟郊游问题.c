#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#define BOOL int
#define TRUE 1
#define FALSE 0

//http://acm.nyist.net/JudgeOnline/problem.php?pid=97
int main()
{
	int n;
	scanf("%d", &n);
	double m,x,y,z;
	while (n--)
	{
		scanf("%lf %lf %lf %lf", &m,&x,&y,&z);
		double t= (x*m)/(y-x);
		double s = z*t;
		printf("%.2f\n",s);
	}
}