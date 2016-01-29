#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

void Display(vector<int>& vr)
{
	copy(vr.begin(), vr.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}
//http://acm.nyist.net/JudgeOnline/problem.php?pid=11
int main()
{
	int count;
	int m;
	cin >> count;
	vector<int> inputdata;
	while (count > 0) {
		cin >> m;
		inputdata.push_back(m);
		count--;
	}	
	for (unsigned int i = 0; i < inputdata.size();i++)
	{			
		vector<int> jishu;
		vector<int> oushu;
		for (unsigned int j = 1; j <=inputdata.at(i); j++)
		{
			int data =j;
			if (data % 2 == 0)
			{
				oushu.push_back(data);
			}
			else
			{
				jishu.push_back(data);
			}			
		}
		Display(jishu);
		Display(oushu);		
	}
	
}
