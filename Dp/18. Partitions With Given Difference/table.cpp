// Partitions With Given Difference
// Link - https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628



#include <iostream>
#include <vector>

using namespace std;

int mod = 1e9 + 7;

class Solution {
public:
	int countPartitions(int n, int diff, vector<int> &arr) {
		int sum = 0;
		for (auto x : arr) sum += x;

		int tar;
		if (sum <= diff || (sum - diff) & 1) return 0;
		else tar = (sum - diff) / 2;

		vector <vector<int>> dp(n, vector<int> (tar + 1));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= tar; j++) {

				int notTaken = 0;
				if (i) notTaken = dp[i - 1][j];
				else if (j == 0) notTaken = 1;

				int taken = 0;
				if (i) {
					if (j >= arr[i]) taken = dp[i - 1][j - arr[i]];
				} else if (j == arr[i]) taken = 1;

				dp[i][j] = (taken + notTaken) % mod;
			}
		}
		return dp[n - 1][tar];
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