#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:

	int frogJump(int n, vector <int> &heights) {

		int oneStep = 0, twoStep = 0;
		for (int i = 2; i <= n; i++) {
			int index = i - 1;

			int curr1 = abs(heights[index] - heights[index - 1]) + oneStep;

			int curr2 = INT_MAX;
			if (i > 2) curr2 = abs(heights[index] - heights[index - 2]) + twoStep;

			int curr = min(curr1, curr2);

			twoStep = oneStep;
			oneStep = curr;
		}

		return oneStep;
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