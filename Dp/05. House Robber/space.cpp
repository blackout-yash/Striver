// 198. House Robber
// Link - https://leetcode.com/problems/house-robber/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	int rob(vector <int> &nums) {
		int n = nums.size();

		int prev1 = 0, prev2 = 0;
		for (int i = 0; i < n; i++) {
			int pick = nums[i] + prev2;

			int nonPick = prev1;

			int curr = max(pick, nonPick);

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

	vector <int> nums(n);
	for (auto &xx : nums) cin >> xx;

	cout << sol.rob(nums);

	return 0;
}