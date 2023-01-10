// Sorting Elements of an Array by Frequency
// Link - https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0



#include <bits/stdc++.h>
using namespace std;

class cmp {
public:
	bool operator() (pair <int, int> &p1, pair <int, int> &p2) {
		if (p1.first < p2.first) return true;
		else if (p1.first == p2.first && p1.second > p2.second) return true;
		return false;
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		map <int, int> m;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			m[x]++;
		}

		priority_queue <pair <int, int>, vector <pair <int, int>>, cmp> pq;

		for (auto x : m) pq.push({x.second, x.first});

		while (!pq.empty()) {
			int num = pq.top().second,
			    range = pq.top().first;
			pq.pop();
			while (range--) cout << num << " ";
		} cout << endl;
	}
	return 0;
}