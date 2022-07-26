// 39. 0 1 Knapsack
// Link - https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxValue(int n, int maxWeight, vector <int> &value, vector <int> &weight, vector <vector<int>> &dp) {
		if (maxWeight < 0) return -1;
		else if (n == -1 || maxWeight == 0) return 0;
		else if (dp[n][maxWeight] != -1) return dp[n][maxWeight];

		int taken = maxValue(n - 1, maxWeight - weight[n], value, weight, dp);
		if (taken != -1) taken += value[n];

		int notTaken = maxValue(n - 1, maxWeight, value, weight, dp);

		return dp[n][maxWeight] = max(taken, notTaken);
	}

	int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
		vector <vector<int>> dp(n, vector<int> (maxWeight + 1, -1));

		int ans = maxValue(n - 1, maxWeight, value, weight, dp);

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