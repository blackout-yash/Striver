// 198. House Robber
// Link - https://leetcode.com/problems/house-robber/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	int maxMoney(int n, vector <int> &nums, vector <int> &dp) {
		if (n < 0) return 0;
		else if (dp[n] != -1) return dp[n];

		int pick = nums[n] + maxMoney(n - 2, nums, dp);

		int nonPick = maxMoney(n - 1, nums, dp);

		int ans = max(pick, nonPick);

		return dp[n] = ans;
	}

	int rob(vector <int> &nums) {
		int n = nums.size();
		vector <int> dp(n, -1);

		int ans = maxMoney(n - 1, nums, dp);

		return ans;
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