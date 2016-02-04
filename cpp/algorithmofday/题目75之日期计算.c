#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int sum_day(int, int);
int leap(int year);

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		
		int year, month, day, days = 0;
		scanf("%d %d %d", &year, &month, &day);
		days = sum_day(month, day);
		if (leap(year) && month >= 3)
		{
			days = days + 1;
		}
		printf("%d\n", days);
	}
	return 0;
}


int sum_day(int month, int day)
{
	int i;
	int day_tab[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	for (i = 0; i < month - 1; i++)
		day += day_tab[i];
	return(day);
}

//ÊÇ·ñÈòÄê
int leap(int year)
{
	int leap;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	return(leap);
}


