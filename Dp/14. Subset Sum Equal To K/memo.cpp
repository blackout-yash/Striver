// 82. Subset Sum Equal To K
// Link - https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0



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

	bool subsetSumToK(int n, int k, vector <int> &arr) {
		vector <vector<int>> dp(n, vector<int> (k + 1, -1));

		bool ans = targetSum(n - 1, k, arr, dp);

		return ans;
	}
};


int main() {
	Solution sol;

	int n, k;
	cin >> n >> k;

	vector <int> arr(n);
	for (auto &xx : arr) cin >> xx;

	cout << sol.subsetSumToK(n, k, arr);

	return 0;
}