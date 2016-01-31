#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int s, a, b, c;
		cin >> s >> a >> b >> c;
		printf("%.2lf\n", s*a / (double)(b - a)*c);
	}

}