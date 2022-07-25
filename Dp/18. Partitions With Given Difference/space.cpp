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

		vector <int> dp(tar + 1);
		for (int i = 0; i < n; i++) {

			vector <int> curr(tar + 1);
			for (int j = 0; j <= tar; j++) {

				int notTaken = 0;
				if (i) notTaken = dp[j];
				else if (j == 0) notTaken = 1;

				int taken = 0;
				if (i) {
					if (j >= arr[i]) taken = dp[j - arr[i]];
				} else if (j == arr[i]) taken = 1;

				curr[j] = (taken + notTaken) % mod;
			}

			for (int j = 0; j <= tar; j++) dp[j] = curr[j];
		}
		return dp[tar];
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