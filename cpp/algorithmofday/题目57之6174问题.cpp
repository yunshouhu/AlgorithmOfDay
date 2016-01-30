#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int donext(char *myints,int len)
{
	sort(myints, myints + len);
	vector<int> datas;
	do {
		//进行全排列
		stringstream strstream;
		if (len > 0 && myints[0] != 0)
		{
			for (int i = 0; i < len; i++)
			{
				strstream << myints[i];
			}
		}
		else
		{
			for (int i = 1; i < len; i++)
			{
				strstream << myints[i];
			}
		}
		int val;
		strstream >> val;
		datas.push_back(val);
		strstream.clear();
	} while (next_permutation(myints, myints + len));    ///获取下一个较大字典序排列

	int min = *std::min_element(datas.begin(), datas.end());
	int max = *std::max_element(datas.begin(), datas.end());	
	int c = max - min;
	if(c==6174)
	{
		return 2;
	}else
	{
		//char item[1024];
		//atoi、atof、itoa、itow函数是windows平台下实现字符串与数值相互转换的函数。Linux平台下请使用标准库中的sprintf与sscanf函数。
		//itoa(c, item, 10);
		//sscanf(item, "%d", c);
		//sprintf(item, "%d", c);
		string item;
		stringstream strstream;
		strstream << c;
		strstream >> item;

		return donext((char*)item.c_str(),len)+1;
	}	
}
//http://acm.nyist.net/JudgeOnline/problem.php?pid=57
//启用itoa PROJECT PROPERTIES->LINKER->GENERAL->ENABLE INCREMENTAL LINKKING and set it to NO
int main(int argvc, char **argv)
{

	int count;
	cin >> count;
	string item;
	while (count--)
	{
		cin >> item;
		int len = item.length();
		char *items= (char*)item.c_str();
		if (len == 4)
		{
			cout << donext(items, len) << endl;
		}
		
	}	
	return 0;
}