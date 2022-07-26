// 39. 0 1 Knapsack
// Link - https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {

		vector <int> dp(maxWeight + 1);
		for (int i = 0; i < n; i++) {

			vector <int> curr(maxWeight + 1);
			for (int j = 0; j <= maxWeight; j++) {

				int notTaken = 0;
				if (i) notTaken = dp[j];

				int taken = 0;
				if (i) {
					if (j >= weight[i]) taken = value[i] + dp[j - weight[i]];
				} else if (j == weight[i]) taken = value[i];

				curr[j] = max(taken, notTaken);
			}

			for (int j = 0; j <= maxWeight; j++) dp[j] = curr[j];
		}

		int ans = 0;
		for (auto x : dp) ans = max(ans, x);

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