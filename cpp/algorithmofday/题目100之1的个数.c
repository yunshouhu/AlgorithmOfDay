#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

//http://acm.nyist.net/JudgeOnline/problem.php?pid=100
int main()
{
	int n;
	scanf("%d", &n);
	int num;
	while (n--)
	{
		scanf("%d", &num);
		//ת��Ϊ������
		int y = 2;
		//string res = "";
		int sum = 0;
		while (num)
		{
			char temp = num %y;
			num /= y;
			//ͳ��1���ֵĴ���
			if (temp == 1)
			{
				sum++;
			}

			if (temp <= 9)
			{
				temp += '0';
			}
			else {
				temp = temp - 10 + 'A';
			}
			//res = temp + res;
		}
		printf("%d\n", sum);

	}
}