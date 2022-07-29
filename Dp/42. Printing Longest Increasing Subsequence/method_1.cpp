// Printing Longest Increasing Subsequence



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void printLIS(int n, vector <int> &nums, vector <vector<int>> &dp) {
		if (n == 1) {
			cout << nums[0] << endl;
			return;
		}

		int value = 1, j = dp[0][0] - 1, prev = 1e9;;
		vector <int> ans(j + 1);
		for (int i = n - 1; i >= 0; i--) {
			if (value != dp[i][0]) {
				value = dp[i][0];
				prev = ans[j]; j--;
			}

			if (prev > nums[i]) ans[j] = max(ans[j], nums[i]);
		}

		for (auto x : ans) cout << x << " ";
		cout << endl;
	}

	int lengthOfLIS(vector<int> &nums) {
		int n = nums.size();
		vector <vector<int>> dp(n, vector<int> (n));

		if (n == 1) {
			printLIS(n, nums, dp);
			return n;
		}

		for (int i = n - 1; i >= 0; i--) {
			for (int j = i - 1; j >= -1; j--) {
				int taken = 0;
				if (j == -1 || nums[j] < nums[i]) {
					if (i + 1 != n) taken = 1 + dp[i + 1][i + 1];
					else taken = 1;
				}

				int notTaken = 0;
				if (i + 1 != n) notTaken = dp[i + 1][j + 1];

				dp[i][j + 1] = max(taken, notTaken);
			}
		}

		printLIS(n, nums, dp);

		return dp[0][0];
	}
};

int main() {
	Solution sol;

	int n;
	cin >> n;

	vector <int> nums(n);
	for (auto &xx : nums) cin >> xx;

	cout << sol.lengthOfLIS(nums);

	return 0;
}