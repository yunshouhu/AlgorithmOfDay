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
�㷨����-�ַ���λ
СQ���������һ�����⣺��һ���ַ����Ĵ�д��ĸ�ŵ��ַ����ĺ��棬�����ַ������λ�ò��䣬�Ҳ����������Ŀռ䡣
���ܰ��СQ��
��������:

���������ж��飬ÿ�����һ���ַ���s���ұ�֤:1<=s.length<=1000.

�������:

����ÿ�����ݣ������λ����ַ�����
��������:
AkleBiCeilD
�������:
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
				//Сд
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
