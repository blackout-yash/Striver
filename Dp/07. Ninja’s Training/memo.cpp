// 112. Ninja’s Training
// Link - https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	int maxPoint(int n, int k, vector <vector <int>> &points, vector <vector <int>> &dp) {
		if (n < 0) return 0;
		else if (dp[n][k] != -1) return dp[n][k];

		int ans = 0;
		for (int i = 0; i < 3; i++) {
			if (i != k) {
				int curr = points[n][k] + maxPoint(n - 1, i, points, dp);

				ans = max(ans, curr);
			}
		}

		return dp[n][k] = ans;
	}

	int vacation(int n, vector<vector<int>> &points) {
		vector <vector <int>> dp(n, vector <int> (3, -1));

		int ans1 = maxPoint(n - 1, 0, points, dp);
		int ans2 = maxPoint(n - 1, 1, points, dp);
		int ans3 = maxPoint(n - 1, 2, points, dp);

		int ans = max({ans1, ans2, ans3});

		return ans;
	}
};

int main() {
	Solution sol;

	int n;
	cin >> n;

	vector <vector<int>> points(n, vector<int> (3));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) cin >> points[i][j];
	}

	cout << sol.vacation(n, points);

	return 0;
}