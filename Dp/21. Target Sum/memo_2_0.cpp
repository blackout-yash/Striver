// 494. Target Sum
// Link - https://leetcode.com/problems/target-sum/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int totalWays(int n, int tar, vector <int> &nums, vector <vector<int>> &dp) {
		if (n == -1) {
			if (tar == 0) return 1;
			return 0;
		} else if (tar < 0) return 0;
		else if (dp[n][tar] != -1) return dp[n][tar];

		int taken = totalWays(n - 1, tar - nums[n], nums, dp);
		int notTaken = totalWays(n - 1, tar, nums, dp);

		return dp[n][tar] = taken + notTaken;
	}


	int findTargetSumWays(vector<int> &nums, int target) {
		int sum = 0, n = nums.size();
		for (auto x : nums) sum += x;

		int tar;
		if (sum < target || (sum - target) & 1) return 0;
		else tar = (sum - target) / 2;

		vector <vector<int>> dp(n, vector<int> (tar + 1, -1));

		int ans = totalWays(n - 1, tar, nums, dp);

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