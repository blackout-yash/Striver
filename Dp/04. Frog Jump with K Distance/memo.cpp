// B - Frog 2
// Link - https://atcoder.jp/contests/dp/tasks/dp_b



#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
	int minCost(int n, int k, vector <int> &heights, vector <int> &dp) {
		if (n == 0) return 0;
		else if (dp[n] != -1) return dp[n];

		int ans = INT_MAX;
		for (int i = 1; i <= k; i++) {
			if (n - i >= 0) {
				int curr = abs(heights[n] - heights[n - i]) + minCost(n - i, k, heights, dp);
				ans = min(ans, curr);
			} else break;
		}

		return dp[n] = ans;
	}

	int frogJump(int n, int k, vector <int> &heights) {
		vector <int> dp(n, -1);

		int ans = minCost(n - 1, k, heights, dp);

		return ans;
	}
};

int main() {
	Solution sol;

	int n, k;
	cin >> n >> k;

	vector <int> heights(n);
	for (auto &xx : heights) cin >> xx;

	cout << sol.frogJump(n, k, heights);

	return 0;
}