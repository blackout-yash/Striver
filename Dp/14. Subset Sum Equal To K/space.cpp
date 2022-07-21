// 82. Subset Sum Equal To K
// Link - https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	bool subsetSumToK(int n, int k, vector <int> &arr) {

		vector <bool> dp(k + 1);
		for (int i = 0; i < n; i++) {

			vector <bool> curr(k + 1);
			for (int j = 0; j <= k; j++) {
				if (arr[i] == j) curr[j] = 1;
				else if (i) {
					bool notTaken = dp[j];

					bool taken = 0;
					if (j >= arr[i]) taken = dp[j - arr[i]];

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

	int n, k;
	cin >> n >> k;

	vector <int> arr(n);
	for (auto &xx : arr) cin >> xx;

	cout << sol.subsetSumToK(n, k, arr);

	return 0;
}