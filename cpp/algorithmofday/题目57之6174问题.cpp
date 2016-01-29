
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

#define arrLen(x) sizeof(x)/sizeof(x[0])

int donext(int *myints,int len)
{
	sort(myints, myints + len);
	vector<int> datas;
	do {
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

	//copy(datas.begin(), datas.end(), ostream_iterator<int>(cout, " "));
	//cout << endl;

	int min = *std::min_element(datas.begin(), datas.end());
	int max = *std::max_element(datas.begin(), datas.end());
	cout << min << " " << max << endl;
	int c = max - min;
	if(c==0)
	{
		return 1;
	}else
	{
		char item[64];
		_itoa(c, item, 10);
		int *items = new int[len];
		for (int i = 0; i < len; i++)
		{
			items[i] = item[i] - '0';
		}
		return donext(items,len);
	}
	
}
int main(int argvc, char **argv)
{

	int count;
	cin >> count;
	string item;
	while (count--)
	{
		cin >> item;
		int len = item.length();
		int *items= new int[len];
		for (int i = 0; i < len;i++)
		{
			items[i]= item[i] -'0';
		}
		cout << donext(items, len) << endl;
	}

	
	return 0;
}