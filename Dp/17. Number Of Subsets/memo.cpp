// 34. Number Of Subsets
// Link - https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532



#include <iostream>
#include <vectoro>
#include <math.h>

using namespace std;

class Solution {
public:
	int totalWays(int n, int tar, vector <int> &num, vector <vector<int>> &dp) {
		if (n == -1) {
			if (tar == 0) return 1;
			return 0;
		} else if (tar < 0) return 0;
		else if (dp[n][tar] != -1) return dp[n][tar];

		int taken = totalWays(n - 1, tar - num[n], num, dp);
		int notTaken = totalWays(n - 1, tar, num, dp);

		return dp[n][tar] = taken + notTaken;
	}

	int findWays(vector<int> &num, int tar) {
		int n = num.size();
		vector <vector<int>> dp(n, vector<int> (tar + 1, -1));

		int ans = totalWays(n - 1, tar, num, dp);

		return ans;
	}
};

int main() {
	Solution sol;

	int n, tar;
	cin >> n >> tar;

	vector <int> num(n);
	for (auto &xx : num) cin >> xx;

	cout << sol.findWays(num, tar);

	return 0;
}