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

        // in this approach, the j runs to -1 becoz we assume that the elements at j == -1 is smaller than the every number.
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i - 1; j >= -1; j--) {
                int taken = 0;
                if (j == -1 || nums[j] < nums[i]) {
                    if (i + 1 != n) taken = 1 + dp[i + 1][i + 1];
                    else taken = 1;
                }

                int notTaken = 0;
                if (i + 1 != n) notTaken = dp[i + 1][j + 1];

                dp[i][j + 1] = max(taken, notTaken);
            }
        }

        return dp[0][0];
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