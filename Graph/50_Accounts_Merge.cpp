// 50. Accounts Merge
// Link - https://leetcode.com/problems/accounts-merge/



class DSU {
public:
	vector <int> parent, _size;

	DSU (int n) {
		parent.resize(n);
		_size.resize(n);
		for (int i = 0; i < n; i++) parent[i] = i;
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
	vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
		int n = accounts.size();
		DSU d(n);

		map <string, int> m;
		for (int i = 0; i < n; i++) {
			int size = accounts[i].size();
			for (int j = 1; j < size; j++) {
				if (m.count(accounts[i][j])) d.unionSets(m[accounts[i][j]], i);
				else m[accounts[i][j]] = i;
			}
		}

		vector <vector<string>> temp(n), ans;
		for (int i = 0; i < n; i++) {
			if (d.findSet(i) == i) {
				temp[i].push_back(accounts[i][0]);
			}
		}

		for (auto x : m) {
			int par = d.findSet(x.second);
			temp[par].push_back(x.first);
		}

		for (auto x : temp) {
			if (x.size()) ans.push_back(x);
		}

		return ans;
	}
};