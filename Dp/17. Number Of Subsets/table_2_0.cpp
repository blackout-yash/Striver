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
		vector <vector<int>> dp(n, vector<int> (tar + 1));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= tar; j++) {

				int notTaken = 0;
				if (i) notTaken = dp[i - 1][j];
				else if (j == 0) notTaken = 1;

				int taken = 0;
				if (i) {
					if (j >= arr[i]) taken = dp[i - 1][j - arr[i]];
				} else if (j == arr[i]) taken = 1;

				dp[i][j] = taken + notTaken;
			}
		}

		return dp[n - 1][tar];
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