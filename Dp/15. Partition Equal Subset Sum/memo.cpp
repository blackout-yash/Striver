// 416. Partition Equal Subset Sum
// Link - https://leetcode.com/problems/partition-equal-subset-sum/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	bool targetSum(int n, int k, vector <int> &arr, vector <vector <int>> &dp) {
		if (n < 0 || k < 0) return 0;
		else if (arr[n] == k) return 1;
		else if (dp[n][k] != -1) return dp[n][k];

		bool notTaken = targetSum(n - 1, k, arr, dp);
		bool taken = targetSum(n - 1, k - arr[n], arr, dp);

		return dp[n][k] = (notTaken | taken);
	}

	bool canPartition(vector<int> &nums) {
		int sum = 0;
		for (auto x : nums) sum += x;
		if (sum & 1) return 0;

		int n = nums.size(), target = sum / 2;
		vector <vector<int>> dp(n, vector<int> (target + 1, -1));

		bool ans = targetSum(n - 1, target, nums, dp);

		return ans;
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