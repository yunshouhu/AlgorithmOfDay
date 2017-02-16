#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	long int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			printf("0\n");
			continue;
		}
		char result[12] = { 0 };
		while (n)
		{
			int m = n % 8;	
			char t[2] = {0};
			sprintf(t, "%d", m);
			strcat(result, t);
			n= n / 8;
		}
		//×Ö·û´®ÄæÐò
		int len = strlen(result);
		for (int i = 0; i < len/2; i++)
		{
			char tmp=result[i];
			result[i] = result[len-i -1];
			result[len-i-1] = tmp;
		}
		//strcpy(result,_strrev(result));//ÄæÐò
		printf("%s\n", result);
		
	}
	return 0;
}