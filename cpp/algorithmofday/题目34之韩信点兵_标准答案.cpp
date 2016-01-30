
#include<iostream>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int n = (a * 70 + b * 21 + c * 15) % 105;
	if (n > 100 || n < 10) 
		cout << "No answer" << endl;
	else 
		cout << n << endl;
}