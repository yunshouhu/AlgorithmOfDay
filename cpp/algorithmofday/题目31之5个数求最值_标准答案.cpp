
#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;
//vs2015��������Ĵ������⣿
int main()
{
	int a[5];
	//copy(istream_iterator<int>(cin), istream_iterator<int>(), a);
	for (int i = 0; i < 5;i++)
	{
		cin >> a[i];
	}
	cout << *min_element(a, a + 5) << " " << *max_element(a, a + 5) << endl;
}