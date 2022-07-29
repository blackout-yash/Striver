// 300. Longest Increasing Subsequence
// Link - https://leetcode.com/problems/longest-increasing-subsequence/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return n;
        vector <vector<int>> dp(n, vector<int> (n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int taken = 0;
                if (nums[i] > nums[j]) {
                    if (j) taken = 1 + dp[j][j - 1];
                    else taken = 1;
                }

                int notTaken = 0;
                if (j) notTaken = dp[i][j - 1];

                dp[i][j] = max(taken, notTaken);
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) ans = max(ans, dp[i][i - 1]);
        return 1 + ans;
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