
#include<iostream>
using namespace std;
int main()
{
	int a;
	while (1)
	{
		cin >> a;
		if (a == 0) break;
		cout << ((a == 153 || a == 370 || a == 371 || a == 407) ? "Yes" : "No") << endl;
	}
}