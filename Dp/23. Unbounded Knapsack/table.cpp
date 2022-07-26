// Unbounded Knapsack
// Link - https://www.codingninjas.com/codestudio/problems/job-sequencing-problem_1169460



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
		vector <vector<int>> dp(n, vector<int> (w + 1));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= w; j++) {
				int notTaken = 0;
				if (i) notTaken = dp[i - 1][j];

				int taken = 0;
				if (j >= weight[i]) taken = profit[i] + dp[i][j - weight[i]];

				dp[i][j] = max(taken, notTaken);
			}
		}

		return dp[n - 1][w];
	}
};

int main() {
	Solution sol;

	int n, w;
	cin >> n >> w;

	vector <int> profit(n);
	for (auto &xx : profit) cin >> xx;

	vector <int> weight(n);
	for (auto &xx : weight) cin >> xx;

	cout << sol.unboundedKnapsack(n, w, profit, weight);

	return 0;
}