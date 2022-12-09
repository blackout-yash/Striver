// 827. Making A Large Island
// Link - https://leetcode.com/problems/making-a-large-island/



const int n = 1e6;
int parent[n], _size[n];

class DSU {
public:
	DSU (int n) {
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

vector <vector <int>> movements = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};

int index(int i, int j, int n) {
	return (i * n) + j;
}

bool isValid(int i, int j, int n) {
	return i >= 0 && i < n && j >= 0 && j < n;
}

class Solution {
public:
	int largestIsland(vector <vector <int>> &grid) {
		int n = grid.size();
		DSU d(n * n);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j]) {
					for (auto move : movements) {
						int x = i + move[0],
						    y = j + move[1];
						if (isValid(x, y, n) && grid[x][y]) {
							int ind1 = index(i, j, n),
							    ind2 = index(x, y, n);
							d.unionSets(ind1, ind2);
						}
					}
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j]) {
					int ind = index(i, j, n),
					    par = d.findSet(ind);
					ans = max(ans, _size[par]);
				} else {
					set <int> s;
					for (auto move : movements) {
						int x = i + move[0],
						    y = j + move[1];
						if (isValid(x, y, n) && grid[x][y]) {
							int ind = index(x, y, n),
							    par = d.findSet(ind);
							s.insert(par);
						}
					}

					int temp = 1;
					for (auto x : s) temp += _size[x];

					ans = max(ans, temp);
				}
			}
		}
		return ans;
	}
};