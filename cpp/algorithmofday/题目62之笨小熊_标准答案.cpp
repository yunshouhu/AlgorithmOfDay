
#include<iostream>
#include<string>
#include<algorithm>
#include<numeric>
using namespace std;

bool isPrime(int n)
{
	if (n == 0) return false;
	if (n == 1) return false;
	if (n == 2) return true;
	for (int i = 2; i*i <= n; i++)
	{
		if (n%i == 0) return false;
	}
	return true;

}
int min_e(int *p, int *q)
{
	int m = 1000;
	for (int* i = p; i != q; i++)
	{
		if (*i < m && *i != 0) m = *i;
	}
	return m;
}
int main()
{
	int n;
	string str;
	cin >> n;
	while (n--)
	{
		int count[26] = { 0 };
		cin >> str;
		for (int i = 0; i != str.size(); ++i)
		{
			++count[str[i] - 'a'];
		}
		int nn = *max_element(count, count + 26) - min_e(count, count + 26);
		if (isPrime(nn)) cout << "Lucky Word" << endl << nn << endl;
		else cout << "No Answer" << endl << 0 << endl;

	}
}