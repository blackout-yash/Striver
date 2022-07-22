// 66. Partition a set into two subsets such that the difference of subset sums is minimum
// Link - https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494



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

	int minSubsetSumDifference(vector<int> &arr, int n) {
		int sum = 0;
		for (auto x : arr) sum += x;

		vector <vector<int>> dp(n, vector<int> (sum + 1, -1));

		int ans = sum;
		for (int i = 0; i <= sum; i++) {
			bool curr = targetSum(n - 1, i, arr, dp);

			if (curr) ans = min(ans, abs(sum - 2 * i));
		}

		return ans;
	}
};

int main() {
	Solution sol;

	int n;
	cin >> n;

	vector <int> arr(n);
	for (auto &xx : arr) cin >> xx;

	cout << sol.minSubsetSumDifference(arr, n);

	return 0;
}