// Number Of Islands
// Link - https://practice.geeksforgeeks.org/problems/number-of-islands/1



// User function Template for C++
class DSU {
public:
	vector <int> parent, _size;

	DSU (int n) {
		parent.resize(n);
		_size.resize(n);
		for (int i = 0; i < n; i++) parent[i] = i;
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

vector <vector <int>> movements = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int i, int j, int n, int m) {
	return i >= 0 && i < n && j >= 0 && j < m;
}

int index(int i, int j, int m) {
	return (i * m) + j;
}

class Solution {
public:
	vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
		DSU d(n * m);
		vector <vector<int>> grid(n, vector<int> (m));

		int curr = 0;
		vector <int> ans;
		for (auto it : operators) {
			int x = it[0], y = it[1];
			if (grid[x][y]) {
				ans.push_back(curr);
				continue;
			}
			curr++;
			grid[x][y] = 1;

			for (auto move : movements) {
				int i = x + move[0],
				    j = y + move[1];

				if (isValid(i, j, n, m) && grid[i][j]) {
					int ind1 = index(x, y, m),
					    ind2 = index(i, j, m);

					if (d.findSet(ind1) != d.findSet(ind2)) {
						curr--;
						d.unionSets(ind1, ind2);
					}
				}
			}
			ans.push_back(curr);
		}
		return ans;
	}
};