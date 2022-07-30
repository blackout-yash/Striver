// 31. Matrix Chain Multiplication
// Link - https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_975344



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int matrixMultiplication(vector<int> &arr, int n) {
		vector <vector<int>> dp(n, vector<int> (n));

		for (int i = n - 1; i > 0; i--) {
			for (int j = i + 1; j < n; j++) {
				int ans = 1e9;
				for (int k = i; k < j; k++) {
					int left = dp[i][k];
					int right = dp[k + 1][j];
					int curr = arr[i - 1] * arr[k] * arr[j];

					ans = min(ans, left + curr + right);
				} dp[i][j] = ans;
			}
		}

		return dp[1][n - 1];
	}
};

int main() {
	Solution sol;

	int n;
	cin >> n;

	vector <int> arr(n);
	for (auto &xx : arr) cin >> xx;

	cout << sol.matrixMultiplication(arr, n);

	return 0;
}