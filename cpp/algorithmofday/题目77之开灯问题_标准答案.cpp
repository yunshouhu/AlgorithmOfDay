
#include <iostream>
using namespace std;
//http://acm.nyist.net/JudgeOnline/problem.php?pid=77
int main()
{
	int n, k, a[1000], i;
	cin >> n >> k;
	for (i = 0; i < n; i++)
		a[i] = 1;
	for (i = 2; i <= k; i++)
		for (int j = 0; j < n; j++)
		{
			if ((j + 1) % i == 0)
				if (a[j] == 0)a[j] = 1;
				else a[j] = 0;
		}
	for (i = 0; i < n; i++)
		if (a[i] == 1)cout << i + 1 << " ";
	cout << endl;
	return 0;
}