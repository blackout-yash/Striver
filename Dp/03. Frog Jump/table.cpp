#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:

	int frogJump(int n, vector <int> &heights) {
		vector <int> dp(n + 1);

		for (int i = 2; i <= n; i++) {
			int index = i - 1;
			int oneStep = abs(heights[index] - heights[index - 1]) + dp[i - 1];

			int twoStep = INT_MAX;
			if (i > 2) twoStep = abs(heights[index] - heights[index - 2]) + dp[i - 2];

			dp[i] = min(oneStep, twoStep);
		}

		return dp[n];
	}
};

int main() {
	Solution sol;

	int n;
	cin >> n;

	vector <int> heights(n);
	for (auto &xx : heights) cin >> xx;

	cout << sol.frogJump(n, heights);

	return 0;
}