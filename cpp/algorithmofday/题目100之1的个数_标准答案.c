
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
void main() { 
	int n, m, s; 
	scanf("%d", &n); 
	while (n--) { 
		scanf("%d", &m);
		s = 0;
		while (m)
		{
			m &= m - 1; //∞¥Œª”Î
			s++;
		}		
		printf("%d\n", s); 
	} 
}