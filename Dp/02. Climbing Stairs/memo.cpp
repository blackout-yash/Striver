// 70. Climbing Stairs
// Link - https://leetcode.com/problems/climbing-stairs/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	int totalWays(int n, vector <int> &dp) {
		if (n < 0) return 0;
		else if (n == 0) return 1;
		else if (dp[n] != -1) return dp[n];

		int oneStep = totalWays(n - 1, dp),
		    twoStep = totalWays(n - 2, dp);

		int curr = oneStep + twoStep;

		return dp[n] = curr;
	}

	int climbStairs(int n) {
		vector <int> dp(n + 1, -1);
		int ans = totalWays(n, dp);
		return ans;
	}
};

int main() {
	Solution sol;

	cout << sol.climbStairs(45);

	return 0;
}