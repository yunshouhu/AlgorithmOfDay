#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#define BOOL int
#define TRUE 1
#define FALSE 0


int str_replace(char *p_result, char* p_source, char* p_search, char *p_repstr)
{
	int c = 0;
	char *p1;
	int nLen = 0;
	int repstr_leng = strlen(p_repstr);
	int searchstr_leng = strlen(p_search);

	do {
		p1 = strstr(p_source, p_search);
		if (p1 == 0)
		{
			strcpy(p_result, p_source);
			return c;
		}
		c++;  //匹配子串计数加1;
		nLen = p1 - p_source;
		memcpy(p_result, p_source, nLen);
		memcpy(p_result + nLen, p_repstr, repstr_leng);
		p_source = p1 + searchstr_leng;
		p_result = p_result + nLen + repstr_leng;
	} while (p1);

	return c;
}

//http://acm.nyist.net/JudgeOnline/problem.php?pid=113
//终于ac了
#define  max  1024

int main()
{


	char str[max] = {0};
	char result[max] = { 0 };
	//gets已经丢弃
	while (fgets(str, max,stdin))
	{
		//scanf("%s",&str)!=EOF		
		str_replace(result,str,"you","we");
		printf("%s\n", result);

	}
}