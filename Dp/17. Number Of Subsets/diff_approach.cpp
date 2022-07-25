// 34. Number Of Subsets
// Link - https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532



#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
	int totalWays(int n, int tar, vector <int> &num, vector <vector<int>> &dp) {
		if (tar == 0) return 1;
		else if (n < 0 || tar < 0) return 0;
		else if (dp[n][tar] != -1) return dp[n][tar];

		int taken = totalWays(n - 1, tar - num[n], num, dp);
		int notTaken = totalWays(n - 1, tar, num, dp);
		return dp[n][tar] = taken + notTaken;
	}

	int findWays(vector<int> &num, int tar) {
		int cnt = 0;
		vector <int> temp;
		for (auto x : num) {
			if (x) temp.push_back(x);
			else cnt++;
		}

		num = temp;
		int n = num.size();
		vector <vector<int>> dp(n, vector<int> (tar + 1, -1));

		int ans = totalWays(n - 1, tar, num, dp);

		return ans * pow(2, cnt);
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