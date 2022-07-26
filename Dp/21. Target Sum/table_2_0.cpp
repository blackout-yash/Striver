// 494. Target Sum
// Link - https://leetcode.com/problems/target-sum/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findTargetSumWays(vector<int> &nums, int target) {
		int sum = 0, n = nums.size();
		for (auto x : nums) sum += x;

		int tar;
		if (sum < target || (sum - target) & 1) return 0;
		else tar = (sum - target) / 2;

		vector <vector<int>> dp(n, vector<int> (tar + 1));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= tar; j++) {

				int notTaken = 0;
				if (i) notTaken = dp[i - 1][j];
				else if (j == 0) notTaken = 1;

				int taken = 0;
				if (i) {
					if (j >= nums[i]) taken = dp[i - 1][j - nums[i]];
				} else if (j == nums[i]) taken = 1;

				dp[i][j] = taken + notTaken;
			}
		}

		return dp[n - 1][tar];
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