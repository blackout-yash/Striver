// 368. Largest Divisible Subset
// Link - https://leetcode.com/problems/largest-divisible-subset/



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int largestDivisibleSubset(int n, vector <int> &nums, vector <int> &dp) {
		if (n < 0) return 0;
		else if (dp[n] != -1) return dp[n];

		int ans = 1;
		for (int i = 1; i <= n; i++) {
			int curr = largestDivisibleSubset(n - i, nums, dp);
			if (nums[n] % nums[n - i] == 0) curr += 1;
			else curr = 0;
			ans = max(ans, curr);
		}

		return dp[n] = ans;
	}

	vector <int> printLargestDivisibleSubset(int n, vector <int> &nums, vector <int> &dp) {
		int ans = *max_element(dp.begin(), dp.end()), index;

		for (int i = 0; i < n; i++) {
			if (dp[i] == ans) {
				index = i;
				break;
			}
		}

		vector <int> store(ans);
		int prev = nums[index];
		for (int i = index; i >= 0; i--) {
			if (dp[i] == ans && prev % nums[i] == 0) {
				store[ans - 1] = nums[i];
				prev = nums[i]; ans--;
			}
		}
		return store;
	}

	vector <int> largestDivisibleSubset(vector<int> &nums) {
		int n = nums.size();
		vector <int> dp(n, -1);

		sort(nums.begin(), nums.end());
		largestDivisibleSubset(n - 1, nums, dp);

		vector <int> ans = printLargestDivisibleSubset(n, nums, dp);

		return ans;
	}
};

int main() {
	Solution sol;

	int n;
	cin >> n;

	vector <int> nums(n);
	for (auto &xx : nums) cin >> xx;

	vector <int> ans = sol.largestDivisibleSubset(nums);

	for (auto x : ans) cout << x << " ";

	return 0;
}