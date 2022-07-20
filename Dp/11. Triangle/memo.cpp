// 120. Triangle
// Link - https://leetcode.com/problems/triangle/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minSum(int i, int j, int n, vector <vector <int>> &triangle, vector <vector <int>> &dp) {
		if (i == n) return 0;
		else if (dp[i][j] != -1) return dp[i][j];

		int down = minSum(i + 1, j, n, triangle, dp);
		int diagonal = minSum(i + 1, j + 1, n, triangle, dp);

		int ans = triangle[i][j] + min(down, diagonal);

		return dp[i][j] = ans;
	}

	int minimumTotal(vector <vector <int>> &triangle) {
		int n = triangle.size();
		vector <vector<int>> dp(n, vector<int> (n, -1));

		int ans = minSum(0, 0, n, triangle, dp);

		return ans;
	}
};

int main() {
	Solution sol;

	int n;
	cin >> n;

	vector <vector<int>> triangle(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int x; cin >> x;
			triangle[i].push_back(x);
		}
	}

	cout << sol.minimumTotal(triangle);

	return 0;
}