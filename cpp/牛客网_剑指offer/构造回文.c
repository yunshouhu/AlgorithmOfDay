#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
1<=s.length<=1000

AkleBiCeilD

kleBiCeilDA

kleiCeilDAB

kleieilDABC

kleieilABCD
*/
//https://www.nowcoder.com/question/next?pid=1725829&qid=44802&tid=6472682
/**
算法基础-字符移位
小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
你能帮帮小Q吗？
输入描述:

输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.

输出描述:

对于每组数据，输出移位后的字符串。
输入例子:
AkleBiCeilD
输出例子:
kleieilABCD
*/
int main()
{
	char line[1001] = {0};
	while (scanf("%s", line) != EOF)
	{
		//printf("%s\n", line);
		int len = strlen(line);
		int Upper_endpos = len-1;

		for (int m = len-1; m >0;m--)
		{
			char hehe = line[m];
			if (hehe >= 'A' && hehe <= 'Z')
			{
				Upper_endpos = m;
				break;
			}
		}
		for (int i = 0; i < len; )
		{
			char hehe = line[i];
			if (hehe >= 'A' && hehe <= 'Z')
			{
				//小写
				for (int j = 0; j < len - i - 1; j++)
				{
					char data = line[i + j];
					line[i + j] = line[i + j+1];
					line[i + j+1] = data;
				}
				Upper_endpos--;
			}
			if (i >Upper_endpos)
			{
				break;
			}
			hehe = line[i];
			if (hehe >= 'a' && hehe <= 'z')
			{
				i++;
			}
		}
		printf("%s\n", line);

	}
	return 0;
}
