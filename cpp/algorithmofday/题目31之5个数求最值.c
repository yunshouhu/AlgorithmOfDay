#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include <stdlib.h>
#define BOOL int
#define TRUE 1
#define FALSE 0
#define arrLen(arr) sizeof(arr)/sizeof(arr[0])

int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}
//http://acm.nyist.net/JudgeOnline/problem.php?pid=31
int main()
{
	int arr[5]={0};
	int len = arrLen(arr);
	for (int i = 0; i < len; i ++)
	{
		scanf("%d", &arr[i]);			
	}
	qsort(arr,5,sizeof(int), compare);
	printf("%d %d\n", arr[0], arr[len-1]);
	
}