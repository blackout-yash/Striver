// 1277. Count Square Submatrices with All Ones
// Link - https://leetcode.com/problems/count-square-submatrices-with-all-ones/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int countSquares(vector<vector<int>> &matrix) {
		int n = matrix.size(), m = matrix[0].size(), ans = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (matrix[i][j]) {
					if (j) matrix[i][j] = 1 + matrix[i][j - 1];

					int _min = 1e9;
					for (int k = 1; k <= (i + 1); k++) {
						_min = min(_min, matrix[i - k + 1][j]);

						if (_min >= k) ans++;
						else break;
					}
				}
			}
		}
		return ans;
	}
};

int main() {
	Solution sol;

	int n, m;
	cin >> n >> m;

	vector <vector<int>> matrix(n, vector<int> (m));
	for (auto &x : matrix) {
		for (auto &y : x) cin >> y;
	}

	cout << sol.countSquares(matrix);

	return 0;
}