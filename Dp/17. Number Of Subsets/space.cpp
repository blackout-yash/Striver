// 34. Number Of Subsets
// Link - https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532



#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
	int findWays(vector<int> &num, int tar) {
		int n = num.size();

		vector <int> dp(tar + 1);
		for (int i = 0; i < n; i++) {

			vector <int> curr(tar + 1);
			for (int j = 0; j <= tar; j++) {
				if (j == 0) curr[j] = 1;

				if (i) curr[j] = dp[j];
				else if (j == num[i]) curr[j]++;

				if (i && j >= num[i]) curr[j] += dp[j - num[i]];
			}

			for (int j = 0; j <= tar; j++) dp[j] = curr[j];
		}

		return dp[tar];
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