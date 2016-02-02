#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define BOOL int
#define TRUE 1
#define FALSE 0
//http://acm.nyist.net/JudgeOnline/problem.php?pid=101
int main()
{
	int n;
	scanf("%d", &n);
	double x1,y1,x2,y2;
	while (n--)
	{
		scanf("%lf %lf %lf %lf", &x1,&y1,&x2,&y2);
		double c1 = fabs(x1 - x2);
		double c2 = fabs(y1 - y2);
		double c = sqrt(c1*c1 + c2*c2);	
		printf("%.2lf\n", c);
	}
}