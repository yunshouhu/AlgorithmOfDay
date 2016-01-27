
#include<iostream>
#include<set>
#include<iterator>
#include <algorithm>
using namespace std;
struct Rect
{
	int num, length, width;

};

bool operator<(const Rect& r1, const Rect& r2)
{
	return r1.num < r2.num || r1.num == r2.num && r1.length < r2.length || r1.num == r2.num&&r1.length == r2.length &&r1.width < r2.width;
}
istream& operator>>(istream& in, Rect& r)
{
	in >> r.num;
	int a, b;
	cin >> a >> b;
	
	r.length = max(a, b);
	r.width = min(a, b);
	return in;
}
ostream& operator<<(ostream& out, const Rect& r)
{
	return out << r.num << " " << r.length << " " << r.width;
}
int main()
{
	int num;
	cin >> num;
	while (num--)
	{
		set<Rect> rs;
		Rect r;
		int n;
		cin >> n;
		while (n--)
		{
			cin >> r;
			rs.insert(r);
		}
		copy(rs.begin(), rs.end(), ostream_iterator<Rect>(cout, "\n"));
	}

}