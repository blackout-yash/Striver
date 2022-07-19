// 112. Ninja’s Training
// Link - https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	int vacation(int n, vector<vector<int>> &points) {
		vector <vector <int>> dp(n, vector <int> (3));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				int prevMax = 0;
				if (i) {
					for (int k = 0; k < 3; k++) {
						if (j != k) prevMax = max(prevMax, dp[i - 1][k]);
					}
				}

				int ans = points[i][j] + prevMax;
				dp[i][j] = ans;
			}
		}

		int ans = *max_element(dp[n - 1].begin(), dp[n - 1].end());

		return ans;
	}
};

int main() {
	Solution sol;

	int n;
	cin >> n;

	vector <vector<int>> points(n, vector<int> (3));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) cin >> points[i][j];
	}

	cout << sol.vacation(n, points);

	return 0;
}