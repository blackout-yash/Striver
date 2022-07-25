// Partitions With Given Difference
// Link - https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628



#include <iostream>
#include <vector>

using namespace std;

int mod = 1e9 + 7;

class Solution {
public:
	int totalWays(int n, int tar, vector <int> &arr, vector <vector<int>> &dp) {
		if (n == -1) {
			if (tar == 0) return 1;
			return 0;
		} else if (tar < 0) return 0;
		else if (dp[n][tar] != -1) return dp[n][tar];

		int taken = totalWays(n - 1, tar - arr[n], arr, dp);
		int notTaken = totalWays(n - 1, tar, arr, dp);

		return dp[n][tar] = (taken + notTaken) % mod;
	}

	int countPartitions(int n, int diff, vector<int> &arr) {
		int sum = 0;
		for (auto x : arr) sum += x;

		int tar;
		if (sum <= diff || (sum - diff) & 1) return 0;
		else tar = (sum - diff) / 2;

		vector <vector<int>> dp(n, vector<int> (tar + 1, -1));

		int ans = totalWays(n - 1, tar, arr, dp);

		return ans;
	}
};

int main() {
	Solution sol;

	int n, diff;
	cin >> n >> diff;

	vector <int> arr(n);
	for (auto &xx : arr) cin >> xx;

	cout << sol.countPartitions(n, diff, arr);

	return 0;
}