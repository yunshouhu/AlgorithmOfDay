
#include<iostream>
#include<string>
#include<algorithm>
#include<numeric>
using namespace std;
int calc(int qm, int py, bool gb, bool xb, bool lw)
{
	int all = 0;
	if (qm > 80 && lw) all += 8000;
	if (qm > 85 && py > 80) all += 4000;
	if (qm > 90) all += 2000;
	if (xb&&qm > 85) all += 1000;
	if (gb&&py > 80) all += 850;
	return all;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int m;
		cin >> m;
		int max_num = 0, all = 0;
		string max_stu;
		while (m--)
		{
			int qm, py, lw;
			string xm, gbs, xbs;
			cin >> xm >> qm >> py >> gbs >> xbs >> lw;
			bool gb = gbs == "Y", xb = xbs == "Y";
			int num = calc(qm, py, gb, xb, lw > 0);
			all += num;
			if (num > max_num) { max_num = num; max_stu = xm; }
		}
		cout << max_stu << endl << max_num << endl << all << endl;
	}
}