
#include<iostream>
using namespace std;
int get(int n, int num)
{
	if (n == 0) return 0;
	else return get(n / num, num) + n / num;
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		cout << get(a, b) << endl;
	}
}