// 300. Longest Increasing Subsequence
// Link - https://leetcode.com/problems/longest-increasing-subsequence/



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(int n, vector <int> &nums, vector <int> &dp) {
        if (n < 0) return 0;
        else if (dp[n] != -1) return dp[n];

        int ans = 1;
        for (int i = 1; i <= n; i++) {
            int curr = lengthOfLIS(n - i, nums, dp);
            if (nums[n] > nums[n - i]) {
                ans = max(ans, curr + 1);
            }
        }

        return dp[n] = ans;
    }

    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        vector <int> dp(n, -1);

        lengthOfLIS(n - 1, nums, dp);

        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution sol;

    int n;
    cin >> n;

    vector <int> nums(n);
    for (auto &xx : nums) cin >> xx;

    cout << sol.lengthOfLIS(nums);

    return 0;
}