// 82. Subset Sum Equal To K
// Link - https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	bool subsetSumToK(int n, int k, vector <int> &arr) {
		vector <vector<bool>> dp(n, vector<bool> (k + 1));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= k; j++) {
				if (arr[i] == j) dp[i][j] = 1;
				else if (i) {
					bool notTaken = dp[i - 1][j];

					bool taken = 0;
					if (j >= arr[i]) taken = dp[i - 1][j - arr[i]];

					dp[i][j] = (taken | notTaken);
				}
			}
		}

		return dp[n - 1][k];
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