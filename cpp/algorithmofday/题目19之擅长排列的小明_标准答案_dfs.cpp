
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int n, m, used[10];
char ans[11];
void dfs(int x, int num)
{
	if (num == m - 1)
	{
		ans[m] = '\0';
		printf("%s\n", ans);
		return;
	}
	int i;
	for (i = 1; i <= n; i++)
	{
		if (!used[i])
		{
			used[i] = 1;
			ans[num + 1] = i + '0';
			dfs(i, num + 1);
			used[i] = 0;
		}
	}
}
int main()
{
	int i, t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; i++)
		{
			memset(used, 0, sizeof(used));
			used[i] = 1;
			ans[0] = i + '0';
			dfs(i, 0);
		}
	}
	return 0;
}