#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
int main()
{
	//freopen("d:\\1.txt","r",stdin);
	//freopen("d:\\2.txt","w",stdout);
	int m;
	scanf("%d", &m);
	while (m--)
	{
		int n, k, sum;
		scanf("%d%d", &n, &k);
		sum = n;
		while (n / k)
		{
			sum += n / k;  n = n / k + n%k;
		}
		printf("%d\n", sum);
	}
	return 0;
}