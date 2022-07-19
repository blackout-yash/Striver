// 70. Climbing Stairs
// Link - https://leetcode.com/problems/climbing-stairs/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	int climbStairs(int n) {
		vector <int> dp(n + 1);

		for (int i = 0; i <= n; i++) {
			if (i <= 1) dp[i] = 1;
			else dp[i] = dp[i - 1] + dp[i - 2];
		}

		return dp[n];
	}
};

int main() {
	Solution sol;

	cout << sol.climbStairs(45);

	return 0;
}