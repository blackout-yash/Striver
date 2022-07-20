// 120. Triangle
// Link - https://leetcode.com/problems/triangle/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	int minimumTotal(vector <vector <int>> &triangle) {
		int n = triangle.size();

		vector <int> dp(n);
		for (int i = n - 1; i >= 0; i--) {

			vector <int> curr(i + 1);
			for (int j = 0; j <= i; j++) {

				int down = 0;
				if (i + 1 != n) down = dp[j];

				int diagonal = 0;
				if (i + 1 != n) diagonal = dp[j + 1];

				curr[j] = triangle[i][j] + min(down, diagonal);
			}

			for (int j = 0; j <= i; j++) dp[j] = curr[j];
		}

		return dp[0];
	}
};

int main() {
	Solution sol;

	int n;
	cin >> n;

	vector <vector<int>> triangle(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int x; cin >> x;
			triangle[i].push_back(x);
		}
	}

	cout << sol.minimumTotal(triangle);

	return 0;
}