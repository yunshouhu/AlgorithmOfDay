
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <ctype.h>

long my_atol(const char *nptr)
{
	int c; /* current char */
	long total; /* current total */
	int sign; /* if ''-'', then negative, otherwise positive */
	while (isspace((int)(unsigned char)*nptr))
		++nptr;

	c = (int)(unsigned char)*nptr++;
	sign = c; /* save sign indication */
	if (c == '-' || c == '+')
		c = (int)(unsigned char)*nptr++; /* skip sign */

	total = 0;

	while (isdigit(c)) {
		total = 10 * total + (c - '0'); /* accumulate digit */
		c = (int)(unsigned char)*nptr++; /* get next char */
	}

	if (sign == '-')
		return -total;
	else
		return total; /* return result, negated if necessary */
}


//自己实现my_atoi 因为atoi为非标准c函数
int  my_atoi(const char *nptr)
{
	return (int)my_atol(nptr);
}


//http://acm.nyist.net/JudgeOnline/problem.php?pid=96
int main() { 
	int n; 
	char num[128];
	int result;
	scanf("%d", &n); 
	while (n--) { 
		scanf("%s",num);
		num[0] = '0';
		result= my_atoi(num);
		printf("%d\n", result);
	} 
	return 0;
}