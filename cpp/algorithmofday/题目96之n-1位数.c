
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
//http://acm.nyist.net/JudgeOnline/problem.php?pid=96
int main() { 
	int n, m; 
	scanf("%d", &n); 
	while (n--) { 
		scanf("%d", &m);
		
		char str[255];
		sprintf(str, "%d", m); //��m=100תΪ10,16���Ʊ�ʾ���ַ�����
		int len = strlen(str);

		int mod = 1;
		for (int i = 1; i < len;i++)
		{
			mod = mod * 10;
		}
		int result = m % mod;
		printf("%d\n", result);
	} 
	return 0;
}