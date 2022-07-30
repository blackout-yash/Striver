// 673. Number of Longest Increasing Subsequence
// Link - https://leetcode.com/problems/number-of-longest-increasing-subsequence/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) {
        int n = nums.size();

        vector <int> dp(n, 1), cnt(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[i] == 1 + dp[j]) cnt[i] += cnt[j];
                    else if (dp[i] < 1 + dp[j]) cnt[i] = cnt[j];

                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        int ans = 0, _max = *max_element(dp.begin(), dp.end());
        for (int i = 0; i < n; i++) {
            if (dp[i] == _max) ans += cnt[i];
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

    cout << sol.findNumberOfLIS(nums);

    return 0;
}