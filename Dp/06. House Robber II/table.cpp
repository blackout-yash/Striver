// 213. House Robber II
// Link - https://leetcode.com/problems/house-robber-ii/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	int rob(vector <int> &nums) {
		int n = nums.size();
		vector <vector<int>> dp(n, vector<int> (2));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				if (!i) dp[i][1] = nums[i];
				else {
					if (i + 1 == n && j) {
						dp[i][j] = dp[i - 1][j];
						continue;
					}

					int pick = nums[i];
					if (i > 1) pick += dp[i - 2][j];

					int nonPick = dp[i - 1][j];

					dp[i][j] = max(pick, nonPick);
				}
			}
		}

		return max(dp[n - 1][0], dp[n - 1][1]);
	}
};

int main() {
	Solution sol;

	int n;
	cin >> n;

	vector <int> nums(n);
	for (auto &xx : nums) cin >> xx;

	cout << sol.rob(nums);

	return 0;
}