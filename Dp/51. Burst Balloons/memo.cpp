// 312. Burst Balloons
// Link - https://leetcode.com/problems/burst-balloons/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxCoins(int i, int j, vector <int> &nums, vector <vector<int>> &dp) {
		if (i > j) return 0;
		else if (dp[i][j] != -1) return dp[i][j];

		int ans = 0;
		for (int k = i + 1; k < j; k++) {
			int left = maxCoins(i, k, nums, dp);
			int right = maxCoins(k, j, nums, dp);
			int curr = nums[i] * nums[k] * nums[j];
			ans = max(ans, left + curr + right);
		} return dp[i][j] = ans;
	}

	int maxCoins(vector<int> &nums) {
		int n = nums.size();
		vector <vector<int>> dp(n + 2, vector<int> (n + 2, -1));

		nums.push_back(1);
		nums.insert(nums.begin(), 1);

		int ans = maxCoins(0, n + 1, nums, dp);

		return ans;
	}
};

int main() {
	Solution sol;

	int n;
	cin >> n;

	vector <int> nums(n);
	for (auto &xx : nums) cin >> xx;

	cout << sol.maxCoins(nums);

	return 0;
}