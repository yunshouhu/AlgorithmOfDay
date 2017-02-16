#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

void getLenForYueshu(int data)
{
	int count = 1;
	for (int i = 1; i <= data / 2; i++)
	{
		if (data % i == 0)
		{
			count++;
		}
	}
	printf("%d\n", count);
}
//主要就是判断一个数 i 有几个约数时从1循环到sqrt(i)即可，不然运行时间会超出要求
void sum_prime(int n)
{
	int sum = 0;
	double tmp = sqrt(n);
	for (int i = 1; i <= tmp; i++){
		if (n % i == 0){
			if (i == tmp){
				sum += 1;
			}
			else{
				sum += 2;
			}
		}
	}
	printf("%d\n", sum);
}

int numOfDivisor(int num)
{
	int ans = 0;
	int i;
	for (i = 1; i*i<num; i++)
	{
		if (num%i == 0)
			ans += 2;
	}
	if (i*i == num) ans++;

	printf("%d\n", ans);
	return ans;
}
//https://www.nowcoder.com/practice/04c8a5ea209d41798d23b59f053fa4d6?tpId=40&tqId=21334&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
/**
约数的个数：
输入n个整数,依次输出每个数的约数的个数
输入描述:
输入的第一行为N，即数组的个数(N<=1000)
接下来的1行包括N个整数，其中每个数的范围为(1<=Num<=1000000000)
当N=0时输入结束。

输出描述:
可能有多组输入数据，对于每组输入数据，
输出N行，其中每一行对应上面的一个数的约数的个数。

输入例子:
5
1 3 4 6 12
输出例子:
1
2
3
4
6
*/
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			int data;
			scanf("%d", &data);
			//getLenForYueshu(data);
			//sum_prime(data);
			numOfDivisor(data);

		}
	}

	return 0;
}