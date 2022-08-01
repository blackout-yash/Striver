// 496. Next Greater Element I
// Link - https://leetcode.com/problems/next-greater-element-i/



#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	vector <int> nextGreaterElement(vector <int> &nums2) {
		int n = nums2.size();
		vector <int> ans(n, -1);

		stack <int> s;
		for (int i = n - 1; i >= 0; i--) {
			while (!s.empty()) {
				if (s.top() > nums2[i]) {
					ans[i] = s.top();
					break;
				} else s.pop();
			} s.push(nums2[i]);
		} return ans;
	}

	vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
		vector <int> nextGreater = nextGreaterElement(nums2);

		map <int, int> index;
		for (int i = 0; i < size(nums2); i++) index[nums2[i]] = i;

		vector <int> ans;
		for (auto x : nums1) {
			ans.push_back(nextGreater[index[x]]);
		}

		return ans;
	}
};

int main() {
	Solution sol;

	int n, m;
	cin >> n >> m;

	vector <int> nums1(n), nums2(m);
	for (auto &xx : nums1) cin >> xx;
	for (auto &xx : nums2) cin >> xx;

	vector <int> ans = sol.nextGreaterElement(nums1, nums2);

	for (auto x : ans) cout << x << " ";

	return 0;
}