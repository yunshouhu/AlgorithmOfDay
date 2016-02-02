#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int main()
{
	int  an[3], i, t, j, max, flag;
	scanf("%d %d %d", &an[0], &an[1], &an[2]);
	for (i = 0; i < 3; i++)
	{
		t = max = an[i];
		flag = i;
		for (j = i; j<3; j++)
			if (an[j]>t)
			{
				max = an[j];
				flag = j;
			};
		t = an[i];
		an[i] = max;
		an[flag] = t;
	}
	for (i = 2; i >= 0; i--)
		printf("%d ", an[i]);
	return 0;
}
