// Unbounded Knapsack
// Link - https://www.codingninjas.com/codestudio/problems/job-sequencing-problem_1169460



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxValue(int n, int w, vector <int> &profit, vector <int> &weight, vector <vector<int>> &dp) {
		if (w < 0) return -1;
		else if (n == -1 || w == 0) return 0;
		else if (dp[n][w] != -1) return dp[n][w];

		int taken = maxValue(n, w - weight[n], profit, weight, dp);
		if (taken != -1) taken += profit[n];

		int notTaken = maxValue(n - 1, w, profit, weight, dp);

		return dp[n][w] = max(taken, notTaken);
	}

	int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
		vector <vector<int>> dp(n, vector<int> (w + 1, -1));

		int ans = maxValue(n - 1, w, profit, weight, dp);

		return ans;
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