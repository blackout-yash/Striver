// 31. Matrix Chain Multiplication
// Link - https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_975344



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int matrixMultiplication(int i, int j, vector <int> &arr, vector <vector<int>> &dp) {
		if (i == j) return 0;
		else if (dp[i][j] != -1) return dp[i][j];

		int ans = 1e9;
		for (int k = i; k < j; k++) {
			int left = matrixMultiplication(i, k, arr, dp);
			int right = matrixMultiplication(k + 1, j, arr, dp);
			int curr = arr[i - 1] * arr[k] * arr[j];
			ans = min(ans, left + curr + right);
		}
		return dp[i][j] = ans;
	}

	int matrixMultiplication(vector<int> &arr, int n) {
		vector <vector<int>> dp(n, vector<int> (n, -1));

		int ans = matrixMultiplication(1, n - 1, arr, dp);

		return ans;
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