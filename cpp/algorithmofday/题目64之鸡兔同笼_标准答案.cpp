
#include<iostream>
using namespace std;
int main()
{
	int n, a, b, p, q;
	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		q = (b - 2 * a) / 2;
		p = a - q;
		if (p < 0 || q < 0 || b % 2) cout << "No answer" << endl;
		else cout << p << " " << q << endl;
	}
}