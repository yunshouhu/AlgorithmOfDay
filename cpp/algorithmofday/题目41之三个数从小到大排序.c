#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define BOOL int
#define TRUE 1
#define FALSE 0

int compare(const void *a, const void *b)
{
	return (*(int*)a)> (*(int*)b);
}

//http://acm.nyist.net/JudgeOnline/problem.php?pid=41
int main()
{
	int arr[64] = { 0 };
	int len = 3;
	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
	qsort(arr, len, sizeof(int), compare);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

}