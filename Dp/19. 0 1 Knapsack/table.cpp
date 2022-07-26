// 39. 0 1 Knapsack
// Link - https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
		vector <vector<int>> dp(n, vector<int> (maxWeight + 1));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= maxWeight; j++) {
				int notTaken = 0;
				if (i) notTaken = dp[i - 1][j];

				int taken = 0;
				if (i) {
					if (j >= weight[i]) taken = value[i] + dp[i - 1][j - weight[i]];
				} else if (j == weight[i]) taken = value[i];

				dp[i][j] = max(taken, notTaken);
			}
		}

		int ans = 0;
		for (auto x : dp[n - 1]) ans = max(ans, x);

		return ans;
	}
};

int main() {
	Solution sol;

	int n, maxWeight;
	cin >> n >> maxWeight;

	vector <int> value(n);
	for (auto &xx : value) cin >> xx;

	vector <int> weight(n);
	for (auto &xx : weight) cin >> xx;

	cout << sol.knapsack(weight, value, n, maxWeight);

	return 0;
}