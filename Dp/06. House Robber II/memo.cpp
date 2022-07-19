// 213. House Robber II
// Link - https://leetcode.com/problems/house-robber-ii/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	int maxMoney(int n, int k, vector <int> &nums, vector <vector<int>> &dp) {
		if (n < 0) {
			if (k == 2) return -nums[0];
			else return 0;
		} else if (dp[n][k] != -1) return dp[n][k];

		bool flag = (n + 1 == nums.size() || !n);

		if  (flag) k++;
		int pick = nums[n] + maxMoney(n - 2, k, nums, dp);

		if (flag) k--;
		int nonPick = maxMoney(n - 1, k, nums, dp);

		int ans = max(pick, nonPick);

		return dp[n][k] = ans;
	}

	int rob(vector <int> &nums) {
		int n = nums.size();
		vector <vector<int>> dp(n, vector<int> (2, -1));

		int ans = maxMoney(n - 1, 0, nums, dp);

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