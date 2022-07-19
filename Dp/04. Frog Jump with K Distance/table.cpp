// B - Frog 2
// Link - https://atcoder.jp/contests/dp/tasks/dp_b



#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
	int frogJump(int n, int k, vector <int> &heights) {
		vector <int> dp(n);

		for (int i = 1; i < n; i++) {
			int ans = INT_MAX;
			for (int j = 1; j <= min(i, k); j++) {
				int curr = abs(heights[i] - heights[i - j]) + dp[i - j];
				ans = min(ans, curr);
			} dp[i] = ans;
		}

		return dp[n - 1];
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