// 503. Next Greater Element II
// Ḷink - https://leetcode.com/problems/next-greater-element-ii/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextGreaterElements(vector <int> &nums, vector <int> &ans) {
        int n = nums.size();

        stack <int> s;
        for (int i = (2 * n) - 1; i >= 0; i--) {
            while (!s.empty()) {
                if (s.top() > nums[i % n]) {
                    ans[i % n] = s.top();
                    break;
                } else s.pop();
            } s.push(nums[i % n]);
        }
    }

    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        vector <int> ans(n, -1);

        nextGreaterElements(nums, ans);

        return ans;
    }
};

int main() {
    Solution sol;

    int n;
    cin >> n;

    vector <int> nums(n);
    for (auto &xx : nums) cin >> xx;

    vector <int> ans = sol.nextGreaterElements(nums);

    for (auto x : ans) cout << x << " ";

    return 0;
}