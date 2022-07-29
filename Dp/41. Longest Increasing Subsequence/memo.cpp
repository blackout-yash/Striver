// 300. Longest Increasing Subsequence
// Link - https://leetcode.com/problems/longest-increasing-subsequence/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int lengthOfLIS(int n, int m, int prev, vector <int> &nums, vector <vector<int>> &dp) {
		if (n < 0) return 0;
		else if (dp[n][m] != -1) return dp[n][m];

		int taken = -1e9;
		if (prev > nums[n]) taken = 1 + lengthOfLIS(n - 1, n, nums[n], nums, dp);
		int notTaken = lengthOfLIS(n - 1, m, prev, nums, dp);

		return dp[n][m] = max(taken, notTaken);
	}

	int lengthOfLIS(vector<int> &nums) {
		int n = nums.size();
		vector <vector<int>> dp(n, vector<int> (n + 1, -1));

		int ans = lengthOfLIS(n - 1, n, 1e9, nums, dp);

		return ans;
	}
};

int main() {
	Solution sol;

	int n;
	cin >> n;

	vector <int> nums(n);
	for (auto &xx : nums) cin >> xx;

	cout << sol.lengthOfLIS(nums);

	return 0;
}