// 213. House Robber II
// Link - https://leetcode.com/problems/house-robber-ii/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	int maxAmount(vector <int> &nums) {
		int n = nums.size();
		if (n == 1) return nums[0];

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

	int rob(vector <int> &nums) {
		int n = size(nums);
		if (n == 1) return nums[0];

		vector <int> arr1, arr2;
		for (int i = 0; i < n; i++) {
			if (i) arr1.push_back(nums[i]);
			if (i + 1 != n) arr2.push_back(nums[i]);
		}

		int ans1 = maxAmount(arr1);
		int ans2 = maxAmount(arr2);

		return max(ans1, ans2);
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