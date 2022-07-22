// 66. Partition a set into two subsets such that the difference of subset sums is minimum
// Link - https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	int minSubsetSumDifference(vector<int> &arr, int n) {
		int sum = 0;
		for (auto x : arr) sum += x;

		vector <bool> dp(sum + 1);
		for (int i = 0; i < n; i++) {

			vector <bool> curr(sum + 1);
			for (int j = 0; j <= sum; j++) {
				if (arr[i] == j) curr[j] = 1;
				else if (i) {
					bool notTaken = dp[j];

					bool taken = 0;
					if (j >= arr[i]) taken = dp[j - arr[i]];

					curr[j] = (taken | notTaken);
				}
			}

			for (int j = 0; j <= sum; j++) dp[j] = curr[j];
		}

		int ans = sum;
		for (int i = 0; i <= sum; i++) {
			bool curr = dp[i];

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