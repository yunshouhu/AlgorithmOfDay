//#include <vld.h>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main() {
	int numGroup;
	cin >> numGroup;
	set<vector<int> > sec;
	int num = 0, length = 0, width = 0;

	for (int iGroup = 0; iGroup < numGroup; ++iGroup) {
		int numInGroup;
		cin >> numInGroup;
		for (int jInGroup = 0; jInGroup < numInGroup; ++jInGroup) {
			cin >> num >> length >> width;
			if (length < width) {
				int tmp = width;
				width = length;
				length = tmp;
			}
			vector<int> vec;
			vec.push_back(num);
			vec.push_back(length);
			vec.push_back(width);
			sec.insert(vec);

		}
	}
	for (set<vector<int> >::const_iterator first = sec.begin(), end = sec.end(); first != end; ++first)
		cout << (*first)[0] << ' ' << (*first)[1] << ' ' << (*first)[2] <<endl;
	sec.clear();

	return 0;
}