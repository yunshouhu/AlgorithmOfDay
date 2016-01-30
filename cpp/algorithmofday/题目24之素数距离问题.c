#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<math.h>
#define BOOL int
#define TRUE 1
#define FALSE 0

BOOL isPrime(int a)
{
	if (a == 1)
	{
		return FALSE;
	}
	for (int i = 2; i <=sqrt(a); i++)
		if (a%i == 0)
			return FALSE;
	return TRUE;
}
//http://acm.nyist.net/JudgeOnline/problem.php?pid=24
//终于ac了
int main()
{
	int n;
	scanf("%d", &n);
	int a, item_up, item_down, item_up_cha=1, item_down_cha=1;
	while (n--)
	{
		scanf("%d", &a);

		if (isPrime(a))
		{
			printf("%d 0\n", a);
			continue;
		}else if (a==1) {
			//处理a=1的情况 要输出2 1
			printf("2 1\n");
		}else {
			item_up_cha = 1, item_down_cha = 1;//全部清1

			while (TRUE)
			{
				item_down = a - item_down_cha;
				
				if (isPrime(item_down))
				{
					break;
				}
				item_down_cha++;
			}
			while (TRUE)
			{
				item_up = a + item_up_cha;
				if (isPrime(item_up))
				{
					break;
				}
				item_up_cha++;
			}
			if (item_up_cha >= item_down_cha)
			{
				printf("%d %d\n", item_down, item_down_cha);
			}else {
				printf("%d %d\n", item_up, item_up_cha);
			}		
		}	
	}
}