// 547. Number of Provinces
// Link - https://leetcode.com/problems/number-of-provinces/



class DSU {
public:
	vector <int> parent, _size;

	DSU (int n) {
		parent.resize(n);
		_size.resize(n);
	}

	void makeSet(int v) {
		parent[v] = v;
		_size[v] = 1;
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
	int findCircleNum(vector<vector<int>>& isConnected) {
		int n = isConnected[0].size();
		DSU d = DSU(n);
		for (int i = 0; i < n; i++) d.makeSet(i);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (isConnected[i][j]) d.unionSets(i, j);
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (d.findSet(i) == i) ans++;
		}
		return ans;
	}
};