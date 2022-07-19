// 62. Unique Paths
// Link - https://leetcode.com/problems/unique-paths/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int nCr(int n, int r) {
		// Combination(n, r) = n! / (r! * (n - r)!)
		// reduce the numerator and denominator
		// C(n, r) = ((n - k + 1) * (n - k + 2) * ... * n) / k!

		long double ans = 1;
		for (int i = 1; i <= r; i++) {
			ans = (ans * (n - r + i)) / i;
		}

		return (int)ans;
	}

	int uniquePaths(int m, int n) {
		int totalStep = n + m - 2;
		int totalRight = m - 1;
		int totalBottom = n - 1;

		// Unique Path = C(totalStep, totalRight) = C(totalStep, totalBottom)

		int ans = nCr(totalStep, totalRight);

		return ans;
	}
};

int main() {
	Solution sol;

	int n, m;
	cin >> n >> m;

	cout << sol.uniquePaths(n, m);

	return 0;
}