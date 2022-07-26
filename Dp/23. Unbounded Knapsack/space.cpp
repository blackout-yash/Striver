// Unbounded Knapsack
// Link - https://www.codingninjas.com/codestudio/problems/job-sequencing-problem_1169460



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {

		vector <int> dp(w + 1);
		for (int i = 0; i < n; i++) {

			vector <int> curr(w + 1);
			for (int j = 0; j <= w; j++) {

				int notTaken = 0;
				if (i) notTaken = dp[j];

				int taken = 0;
				if (j >= weight[i]) taken = profit[i] + curr[j - weight[i]];

				curr[j] = max(taken, notTaken);
			}

			for (int j = 0; j <= w; j++) dp[j] = curr[j];
		}

		return dp[w];
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