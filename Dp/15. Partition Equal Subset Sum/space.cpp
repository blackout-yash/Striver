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

		vector <bool> dp(k + 1);
		for (int i = 0; i < n; i++) {

			vector <bool> curr(k + 1);
			for (int j = 0; j <= k; j++) {
				if (nums[i] == j) curr[j] = 1;
				else if (i) {
					bool notTaken = dp[j];

					bool taken = 0;
					if (j >= nums[i]) taken = dp[j - nums[i]];

					curr[j] = (taken | notTaken);
				}
			}

			for (int j = 0; j <= k; j++) dp[j] = curr[j];
		}

		return dp[k];
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