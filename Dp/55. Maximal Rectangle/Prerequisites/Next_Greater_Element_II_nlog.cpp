// 503. Next Greater Element II
// Ḷink - https://leetcode.com/problems/next-greater-element-ii/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int inf = -(1e9 + 10);
    void nextGreaterElements(vector <int> &nums, vector <int> &ans) {
        int n = nums.size();

        stack <int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (ans[i] == inf && !s.empty()) {
                if (s.top() > nums[i]) {
                    ans[i] = s.top();
                    break;
                } else s.pop();
            } s.push(nums[i]);
        }
    }

    void firstGreaterElements(vector <int> &nums, vector <int> &ans) {
        int n = nums.size();

        vector <int> arr;
        for (auto x : nums) {
            if (arr.empty()) arr.push_back(x);
            else if (x > arr.back()) arr.push_back(x);
        }

        for (int i = 0; i < n; i++) {
            if (ans[i] == inf) {
                auto it = lower_bound(arr.begin(), arr.end(), nums[i] + 1);
                if (it != arr.end()) {
                    int index = it - arr.begin();
                    ans[i] = arr[index];
                }
            }
        }
    }

    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        vector <int> ans(n, inf);

        nextGreaterElements(nums, ans);
        firstGreaterElements(nums, ans);

        for (auto &x : ans) {
            if (x == inf) x = -1;
        }

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