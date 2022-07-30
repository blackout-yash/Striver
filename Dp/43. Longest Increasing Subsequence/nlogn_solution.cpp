// 300. Longest Increasing Subsequence
// Link - https://leetcode.com/problems/longest-increasing-subsequence/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();

        vector <int> dp;
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            if (it == dp.end()) dp.push_back(nums[i]);
            else {
                int index = it - dp.begin();
                dp[index] = nums[i];
            }
        }

        return size(dp);
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