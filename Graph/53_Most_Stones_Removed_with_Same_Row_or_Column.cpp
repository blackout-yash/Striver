// 947. Most Stones Removed with Same Row or Column
// Link - https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/



class DSU {
public:
	vector <int> parent, _size;

	DSU (int n) {
		parent.resize(n);
		_size.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			_size[i] = 1;
		}
	}

	int findSet(int v) {
		if (v == parent[v]) return v;
		return parent[v] = findSet(parent[v]);
	}

	void unionSets(int a, int b) {
		a = findSet(a);
		b = findSet(b);
		if (a != b) {
			if (_size[a] < _size[b]) swap(a, b);
			parent[b] = a;
			_size[a] += _size[b];
		}
	}
};

class Solution {
public:
	int removeStones(vector <vector<int>> &stones) {
		int n = stones.size(), row = 0, col = 0;
		for (auto x : stones) {
			row = max(row, x[0]);
			col = max(col, x[1]);
		}

		map <int, int> m;
		DSU d(row + col + 2);
		for (auto x : stones) {
			int currRow = x[0],
			    currCol = x[1] + row + 1;
			d.unionSets(currRow, currCol);
			m[currRow] = m[currCol] = 1;
		}

		int cnt = 0;
		for (auto x : m) {
			if (d.findSet(x.first) == x.first) cnt++;
		}

		return n - cnt;
	}
};