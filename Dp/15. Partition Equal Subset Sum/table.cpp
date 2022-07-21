// 416. Partition Equal Subset Sum
// Link - https://leetcode.com/problems/partition-equal-subset-sum/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	bool canPartition(vector<int> &nums) {
		int sum = 0;
		for (auto x : nums) sum += x;
		if (sum & 1) return 0;

		int n = nums.size(), k = sum / 2;
		vector <vector<bool>> dp(n, vector<bool> (k + 1));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= k; j++) {
				if (nums[i] == j) dp[i][j] = 1;
				else if (i) {
					bool notTaken = dp[i - 1][j];

					bool taken = 0;
					if (j >= nums[i]) taken = dp[i - 1][j - nums[i]];

					dp[i][j] = (taken | notTaken);
				}
			}
		}

		return dp[n - 1][k];
	}
};


int main() {
	Solution sol;

	int n;
	cin >> n;

	vector <int> nums(n);
	for (auto &xx : nums) cin >> xx;

	cout << sol.canPartition(nums);

	return 0;
}