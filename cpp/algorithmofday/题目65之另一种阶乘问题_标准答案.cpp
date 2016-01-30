

#include<iostream>
using namespace std;
int f(int n)
{
	if (n % 2) return n == 1 ? 1 : n*f(n - 2);
	return f(n - 1);
}
int g(int n)
{
	return n ? g(n - 1) + f(n) : 0;
}
int main()
{
	int n, m;
	cin >> n;
	while (n--)
	{
		cin >> m;
		cout << g(m) << endl;
	}
}