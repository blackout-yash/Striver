// 198. House Robber
// Link - https://leetcode.com/problems/house-robber/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	int rob(vector <int> &nums) {
		int n = nums.size();
		vector <int> dp(n);

		for (int i = 0; i < n; i++) {
			int pick = nums[i];
			if (i > 1) pick += dp[i - 2];

			int nonPick = 0;
			if (i) nonPick = dp[i - 1];

			dp[i] = max(pick, nonPick);
		}

		return dp[n - 1];
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