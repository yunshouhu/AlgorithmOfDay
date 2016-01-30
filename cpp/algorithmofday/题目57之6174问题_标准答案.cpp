#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main()
{
	int k;
	cin >> k;
	while (k--)
	{
		int n, a[4], n1, n2;
		scanf("%d", &n);
		int s = 1;
		while (n != 6174)
		{
			a[0] = n % 10;
			a[3] = n / 1000;
			a[1] = n / 10 % 10;
			a[2] = n / 100 % 10;
			sort(a, a + 4);
			n1 = 1000 * a[3] + 100 * a[2] + 10 * a[1] + a[0];
			n2 = 1000 * a[0] + 100 * a[1] + 10 * a[2] + a[3];
			n = n1 - n2;
			s++;
		}
		printf("%d\n", s);
	}
}