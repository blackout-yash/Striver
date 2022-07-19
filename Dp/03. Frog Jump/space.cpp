#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:

	int frogJump(int n, vector <int> &heights) {

		int prev1 = 0, prev2 = 0;
		for (int i = 2; i <= n; i++) {
			int index = i - 1;

			int jumpOne = abs(heights[index] - heights[index - 1]) + prev1;

			int jumpTwo = INT_MAX;
			if (i > 2) jumpTwo = abs(heights[index] - heights[index - 2]) + prev2;

			int curr = min(jumpOne, jumpTwo);

			prev2 = prev1;
			prev1 = curr;
		}

		return prev1;
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