// 1547. Minimum Cost to Cut a Stick
// Link - https://leetcode.com/problems/minimum-cost-to-cut-a-stick/



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minCost(int i, int j, vector <int> &cuts, vector <vector<int>> &dp) {
		if (i > j) return 0;
		else if (dp[i][j] != -1) return dp[i][j];

		int ans = 1e9;
		for (int k = i; k <= j; k++) {
			int left = minCost(i, k - 1, cuts, dp);
			int right = minCost(k + 1, j, cuts, dp);
			int curr = cuts[j + 1] - cuts[i - 1];
			ans = min(ans, left + curr + right);
		}

		return dp[i][j] = ans;
	}

	int minCost(int n, vector<int> &cuts) {
		int c = cuts.size();
		vector <vector<int>> dp(c + 1, vector<int> (c + 1, -1));

		cuts.insert(cuts.begin(), 0);
		cuts.push_back(n);
		sort(cuts.begin(), cuts.end());

		int ans = minCost(1, c, cuts, dp);

		return ans;
	}
};

int main() {
	Solution sol;

	int n, m;
	cin >> n >> m;

	vector <int> cuts(m);
	for (auto &xx : cuts) cin >> xx;

	cout << sol.minCost(n, cuts);

	return 0;
}