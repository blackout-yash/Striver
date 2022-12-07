// 1319. Number of Operations to Make Network Connected
// Link - https://leetcode.com/problems/number-of-operations-to-make-network-connected/



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
	int makeConnected(int n, vector <vector<int>> & connections) {
		if (n > connections.size() + 1) return -1;

		DSU d(n);
		for (int i = 0; i < n; i++) d.makeSet(i);

		for (auto it : connections) d.unionSets(it[0], it[1]);

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (d.findSet(i) == i) ans++;
		}

		return ans - 1;
	}
};