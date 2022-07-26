// 494. Target Sum
// Link - https://leetcode.com/problems/target-sum/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int totalWays(int n, int target, int factor, vector <int> &nums, vector <vector<int>> &dp) {
		if (n == -1) {
			if (target) return 0;
			return 1;
		} else if (dp[n][target + factor] != -1) return dp[n][target + factor];


		int plus = totalWays(n - 1, target + nums[n], factor, nums, dp);
		int minus = totalWays(n - 1, target - nums[n], factor, nums, dp);

		return dp[n][target + factor] = plus + minus;
	}

	int findTargetSumWays(vector<int> &nums, int target) {
		int n = nums.size(), sum = 0;
		for (auto x : nums) sum += x;

		if (abs(target) > sum) return 0;

		int factor = abs(target) + sum;
		vector <vector<int>> dp(n, vector<int> ((2 * factor) + 1, -1));

		int ans = totalWays(n - 1, target, factor, nums, dp);

		return ans;
	}
};

int main() {
	Solution sol;

	int n, target;
	cin >> n >> target;

	vector <int> nums(n);
	for (auto &xx : nums) cin >> xx;

	cout << sol.findTargetSumWays(nums, target);

	return 0;
}