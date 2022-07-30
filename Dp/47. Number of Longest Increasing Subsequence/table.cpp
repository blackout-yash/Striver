// 673. Number of Longest Increasing Subsequence
// Link - https://leetcode.com/problems/number-of-longest-increasing-subsequence/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findNumberOfLIS(vector<int> &nums) {
		int n = nums.size();

		vector <int> dp(n, 1);
		vector <vector<int>> cnt(n, vector<int> (n + 1));
		for (int i = 0; i < n; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (nums[i] > nums[j]) {
					dp[i] = max(dp[i], 1 + dp[j]);

					cnt[i][dp[j] + 1] += max(cnt[j][dp[j]], 1);
				}
			}
		}

		int ans = n;
		for (int i = n; i > 0; i--) {
			int curr = 0;
			for (int j = 0; j < n; j++) curr += cnt[j][i];
			if (curr) {
				ans = curr;
				break;
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;

	int n;
	cin >> n;

	vector <int> nums(n);
	for (auto &xx : nums) cin >> xx;

	cout << sol.findNumberOfLIS(nums);

	return 0;
}