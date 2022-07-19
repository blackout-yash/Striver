// 119. Frog Jump
// Link - https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=0



#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:

	int minEnergy(int n, vector <int> &heights, vector <int> &dp) {
		if (n == 1) return 0;
		else if (dp[n] != -1) return dp[n];

		int index = n - 1;
		int jumpOne = abs(heights[index] - heights[index - 1]) + minEnergy(n - 1, heights, dp);

		int jumpTwo = INT_MAX;
		if (n > 2) jumpTwo = abs(heights[index] - heights[index - 2]) + minEnergy(n - 2, heights, dp);

		int ans = min(jumpOne, jumpTwo);

		return dp[n] = ans;
	}

	int frogJump(int n, vector <int> &heights) {
		vector <int> dp(n + 1, -1);

		int ans = minEnergy(n, heights, dp);

		return ans;
	}
};

int main() {
	Solution sol;

	int n;
	cin >> n;

	vector <int> heights(n);
	for (auto &xx : heights) cin >> xx;

	cout << sol.frogJump(n, heights);

	return 0;
}