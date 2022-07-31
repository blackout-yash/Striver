// 312. Burst Balloons
// Link - https://leetcode.com/problems/burst-balloons/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxCoins(vector<int> &nums) {
		int n = nums.size();
		vector <vector<int>> dp(n + 2, vector<int> (n + 2));

		nums.push_back(1);
		nums.insert(nums.begin(), 1);

		for (int i = n; i >= 0; i--) {
			for (int j = i; j <= n + 1; j++) {
				int ans = 0;
				for (int k = i + 1; k < j; k++) {
					int left = dp[i][k];
					int right = dp[k][j];
					int curr = nums[i] * nums[k] * nums[j];
					ans = max(ans, left + curr + right);
				} dp[i][j] = ans;
			}
		}

		return dp[0][n + 1];
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